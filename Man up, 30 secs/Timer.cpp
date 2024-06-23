#include "Timer.h"

void Timer::restart()
{
    pass_time = 0;
    is_shotted = false;
}

void Timer::set_interval(int val)
{
    wait_time = val;
}

void Timer::set_loop(bool in)
{
    is_loop = in;
}

void Timer::set_shot_callback(std::function<void()> callback)
{
    shot_callback = callback;
}

void Timer::pause()
{
    is_pause = true;
}

void Timer::resume()
{
    is_pause = false;
}

void Timer::on_update(int delta)
{
    if (is_pause)
        return;

    pass_time += delta;

    if (pass_time >= wait_time)
    {
        if ((!is_shotted || (is_shotted && is_loop)) && shot_callback)
            shot_callback();

        is_shotted = true;
        pass_time -= wait_time;
    }
}
