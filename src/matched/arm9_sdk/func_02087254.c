/*
 * function: func_02087254
 * address:  0x02087254
 * packet:   pkt_02087254
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
*/

typedef unsigned long u32;

typedef struct OSiAlarm {
    void (*handler)(void *arg);
    void *arg;
    u32 tag;
} OSAlarm;

void func_02087254(OSAlarm *alarm)
{
    alarm->handler = 0;
    alarm->tag = 0;
}
