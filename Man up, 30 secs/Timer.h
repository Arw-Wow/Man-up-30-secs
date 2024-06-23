#pragma once

#include <functional>

class Timer
{
public:

	Timer() = default;
	~Timer() = default;

	void restart();

	void set_interval(int val);

	void set_loop(bool in);

	void set_shot_callback(std::function <void()> callback);

	void pause();

	void resume();

	void on_update(int delta);

private:

	int pass_time = 0;
	int wait_time = 0;
	bool is_loop = false;
	bool is_shotted = false;
	bool is_pause = false;
	
	std::function <void()> shot_callback;

};

