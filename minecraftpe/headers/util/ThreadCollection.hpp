#pragma once
#include <_types.h>
#include <deque>
#include <vector>
#include <mutex>
#include <thread>
#include <memory>

struct Job;
struct ThreadCollection
{
	std::vector<std::thread> threads;
	std::deque<std::shared_ptr<Job>> field_C;
	std::deque<std::shared_ptr<Job>> field_34;
	std::mutex mutex;
	std::mutex field_60;
	int field_64; //TODO figure out the type of this thing
	bool isStopped;

	ThreadCollection(uint32_t);
	void enqueue(std::shared_ptr<Job>);
	void processUIThread();
	~ThreadCollection();
};
