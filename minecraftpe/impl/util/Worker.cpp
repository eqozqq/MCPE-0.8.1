#include <util/Worker.hpp>
#include <util/ThreadCollection.hpp>

Worker::Worker(ThreadCollection& a2) {
	this->field_0 = &a2;
}
void Worker::operator()(void) {
	std::unique_lock<std::mutex> v24(this->field_0->mutex, std::defer_lock); //TODO check is defer_lock
	v24.lock();
	/*while(1) {
		if(this->field_0->isStopped) {
			break;
		}

		if(!this->field_0->field_C.empty()) {
			auto&& el = this->field_0->field_C.front();
			this->field_0->field_C.pop_front(); //TODO check;

		}
	}*/
}
