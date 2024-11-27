#include "shape.h"
#include "task.h"
#include "awaitor.h"

#include <string>
#include <unistd.h>
#include <spdlog/spdlog.h>

using namespace Concurrency;
using namespace Geometry;

void Sleep()
{
    spdlog::info("Sleep() -> Going to sleep.");
    sleep(1);
    spdlog::info("Sleep() -> Waking up.");
}

void RaiseTimeout()
{
    const int max_attempts = 5;
    int attempt_cnt = 0;
    while(attempt_cnt < max_attempts)
    {
        spdlog::info("RaiseTimeout() -> Pretending to do work " + std::to_string(attempt_cnt+1) + " times.");
        sleep(1);
        ++attempt_cnt;
    }

    spdlog::info("RaiseTimeout() -> Timeout raised after " + std::to_string(max_attempts) + " attempts.");
}

Task AwaitorTask()
{
    std::function<void()> sleep_job = Sleep;
    co_await Awaitor(sleep_job);
    std::function<void()> raise_timeout_job = RaiseTimeout;
    co_await Awaitor(raise_timeout_job);
}

int main()
{
    spdlog::info("main() -> Hello!\n");
    Shape s = Shape(3);

    Task handle = AwaitorTask();
    handle.Resume();

    return 0;
}