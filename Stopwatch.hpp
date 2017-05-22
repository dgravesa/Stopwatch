/*
	Daniel Graves
	Stopwatch.cpp
*/

#include <chrono>

class Stopwatch
{
public:
	Stopwatch(bool go = false);

	void start();
	void stop();

	void set(float value);
	void reset();

	float read() const;
	float lap();

private:
	bool stopped;
	std::chrono::system_clock::time_point last_start;
	float reading;
};

Stopwatch::Stopwatch(bool go)
{
	stopped = !go;
	reading = 0.0;

	if (go) last_start = std::chrono::system_clock::now();
}

void Stopwatch::start()
{
	if (stopped)
	{
		stopped = false;
		last_start = std::chrono::system_clock::now();
	}
}

void Stopwatch::stop()
{
	if (!stopped)
	{
		std::chrono::duration<float> since_start = std::chrono::system_clock::now() - last_start;
		reading += since_start.count();
		stopped = true;
	}
}

void Stopwatch::set(float value)
{
	reading = value;
}

void Stopwatch::reset()
{
	reading = 0.0;
}

float Stopwatch::read() const
{
	if (stopped) return reading;

	else
	{
		std::chrono::duration<float> since_start = std::chrono::system_clock::now() - last_start;
		return reading + since_start.count();
	}
}

float Stopwatch::lap()
{
	if (stopped) return 0.0;

	else
	{
		float last_reading = reading;
		reading = 0.0;

		std::chrono::duration<float> since_start = std::chrono::system_clock::now() - last_start;
		last_start = std::chrono::system_clock::now();

		return last_reading + since_start.count();
	}
}

