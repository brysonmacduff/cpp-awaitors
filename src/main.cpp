#include "shape.h"
#include "task.h"
#include "awaitor.h"

#include <string>
#include <unistd.h>
#include <spdlog/spdlog.h>

using namespace Concurrency;
using namespace Geometry;

void Sleeper()
{
    spdlog::info("Sleeper() -> Going to sleep.");
    sleep(1);
    spdlog::info("Sleeper() -> Waking up.");
}

void TimeoutRaiser()
{
    const int max_attempts = 5;
    int attempt_cnt = 0;
    while(attempt_cnt < max_attempts)
    {
        spdlog::info("TimeoutRaiser() -> Pretending to do work " + std::to_string(attempt_cnt+1) + " times.");
        sleep(1);
        ++attempt_cnt;
    }

    spdlog::info("TimeoutRaiser() -> Timeout raised after " + std::to_string(max_attempts) + " attempts.");
}

Task AwaitorTask()
{
    std::function<void()> sleeper_job = Sleeper;
    co_await Awaitor(sleeper_job);
    std::function<void()> timeout_raiser_job = TimeoutRaiser;
    co_await Awaitor(timeout_raiser_job);
}

int main()
{
    spdlog::info("main() -> Hello!\n");
    Shape s = Shape(3);

    Task handle = AwaitorTask();
    handle.Resume();

    return 0;
}