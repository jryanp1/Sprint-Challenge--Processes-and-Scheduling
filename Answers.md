1.a. P1: 0 - 32,000; P2: 32,001 - 64,000. User mode starts at address 0 and occupies the lower portion of the address space, extending up to the platform-specific task size limit (which is referenced, for example, in the file named include/asm/processor.h). 


2. All possible process states are:

°Created or "new" state. Waiting to be moved into "ready" state by a long-term admission scheduler. 

°Ready or "waiting" process -loaded into main memory and is waiting to be context switched onto the CPU by the short-term dispatcher scheduler and kept in the ready queue a.k.a. run queue. 

°Running -A process is chosen for execution in either user mode or kernel mode by one of the CPUs (or cores), Maximum = one running process per CPU.
-Kernel mode processes allow unrestricted access to hardware and can access both kernel and user addresses.
Privileged instructions (such as I/O or halt instructions) can be executed only in kernel mode. A system call from a user program leads to a switch to kernel mode.
-User mode processes can access only their own instructions and data on behalf of a user application (until it requests a service from the operating system via a system call, then it switches to kernel mode to do it).Each user mode process has an isolated virtual address space & is banned from direct access to any hardware device.

°Blocked processes can't continue without an external change in state or event, such as, for example, trying to print when the printer is not available, or waiting on user input, or when they require access to a critical section which must be executed atomically. A synchronization object such as a semaphore or mutex provides protection in these cases.

°A terminated or zombie process is dead but stays in the process table until its parent process calls the wait system call to read its exit status, to remove it from the process table. If the parent fails to call wait, this continues to consume the process identifier or PID), and causes a resource leak.

In systems that support virtual memory, there are 2 more possible states:
Swapped out(suspended) and waiting
-removed from main memory and placed on external storage by the scheduler and then back into the waiting state if needed.
Swapped out (suspended) and blocked
-The same as above, but can be put into the blocked state, until an awaited resource is available.



3. A printf call is super super duper fast. Essentially.


4.Printf buffers its output(stores its result in a memory buffer which is a multiple of the drive sector size), only calling write when the buffer is full, or on some other conditions. Also, every time there is an \n, printf flushes out. Write does not flush. Also, it writes a lot more often and sometimes a lot bigger size of data (maybe a whole sector, at times).
