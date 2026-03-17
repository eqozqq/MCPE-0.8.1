#include <util/ThreadCollection.hpp>
#include <stdio.h>
#include <util/Job.hpp>
#include <unistd.h>
#include <util/Worker.hpp>

static int sub_D66E4980() {
	int v0; // r0
	v0 = sysconf(97);
	return v0 & ~(v0 >> 31);
}
ThreadCollection::ThreadCollection(uint32_t a2) {
	if(a2 == 0) {
		int v4 = sub_D66E4980();
		if(v4) a2 = v4;
		else a2 = 1;
	}
	for(unsigned int i = 0; i != a2; ++i) {
		//this causes evil and malicious crashes and other stuff
	//	this->threads.emplace_back(std::thread(Worker(*this))); //TODO check
	}
}
void ThreadCollection::enqueue(std::shared_ptr<Job> a2) {
	//TODO check
	std::unique_lock<std::mutex> v11(this->mutex, std::defer_lock);
	v11.lock();
	this->field_C.emplace_back(a2);
	v11.unlock();
}
void ThreadCollection::processUIThread() {
	for(auto&& it = this->field_34.begin(); it != this->field_34.end();) {

		if(it->get()->status == JS_3) {
			it->get()->finish();
		}
		it = this->field_34.erase(it); //TODO check
	}
}
ThreadCollection::~ThreadCollection() {
	{
		std::unique_lock<std::mutex> a(this->mutex, std::defer_lock);
		a.lock(); //TODO not defer_lock?
		std::unique_lock<std::mutex> b(this->field_60, std::defer_lock);
		b.lock(); //TODO not defer_lock?
		this->isStopped = 1;
	}
	printf("ThreadCollection::~ThreadCollection - not implemented\n");
}
