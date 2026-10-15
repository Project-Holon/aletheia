/*
 * function: OS_CreateVAlarm
 * address:  0x020876A4
 * packet:   pkt_020876A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     os_valarm.o OS_CreateVAlarm.
 */

typedef struct {
    void *handler;
    int _1;
    void *tag;
    int _2[5];
    int finish;
} OSVAlarm;

void OS_CreateVAlarm(OSVAlarm *alarm)
{
    alarm->handler = 0;
    alarm->tag = 0;
    alarm->finish = 0;
}
