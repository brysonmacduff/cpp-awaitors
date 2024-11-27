#include "task.h"

using namespace Concurrency;

Task::Task(std::coroutine_handle<promise_type> ch)
{
    coroutine = ch;
}

std::suspend_always Task::promise_type::initial_suspend()
{
    return {};
}

Task Task::promise_type::get_return_object()
{
    return Task(std::coroutine_handle<promise_type>::from_promise(*this));
}

std::suspend_never Task::promise_type::final_suspend() noexcept 
{
    return {};
}

std::suspend_always Task::promise_type::yield_value(int code)
{
    yield_code = code;
    return {};
}

int Task::GetYieldCode()
{
    return coroutine.promise().yield_code;
}

void Task::promise_type::return_void()
{
    return;
}

void Task::Resume()
{
    coroutine.resume();
}

void Task::Destroy()
{
    coroutine.destroy();
}

bool Task::IsDone()
{
    return coroutine.done();
}

void Task::promise_type::unhandled_exception(){
    exit(1);
}