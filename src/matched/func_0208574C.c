/*
 * function: func_0208574C
 * address:  0x0208574C
 * packet:   pkt_0208574C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     os_thread.o OS_IsThreadTerminated.
 */

typedef struct {
    char pad[0x64];
    int state;
} OSThread;

int func_0208574C(const OSThread *thread)
{
    return (thread->state == 2) ? 1 : 0;
}
