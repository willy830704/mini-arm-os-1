#ifndef __THREADS_H__
#define __THREADS_H__

/* Thread Control Block */
typedef struct __tcb {
	void *stack;
	void *orig_stack;
	uint8_t id;
	uint8_t state;
	uint8_t priority;
	struct __tcb *next;
} tcb_t;

enum {
	THREAD_NONE,
	THREAD_ACTIVE,
	THREAD_SLEEP
};

enum {
	PRIO_DEFAULT = 0,
	PRIO_LOW,
	PRIO_MID,
	PRIO_HIGH
};


void thread_start();
int thread_create(void (*run)(void*), void* userdata, int priority);
void thread_kill(int thread_id);
void thread_self_terminal();
void thread_wake(int thread_id);
void thread_sleep(int thread_id);
int get_thread_id();

#endif
