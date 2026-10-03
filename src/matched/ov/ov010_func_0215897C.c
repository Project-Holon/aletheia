/*
 * function: func_0215897C
 * address:  0x0215897C
 * packet:   pkt_ov010_0215897C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Queue a task on the script's event list.
 *
 * symbols:
 *   func_02158F50  0x02158F50  thumb  ov010
 *   func_02012374  0x02012374  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;

extern void *func_02158F50(void *vm);
struct Evt;
extern void func_02012374(struct Evt *evt, struct Evt **out);

void func_0215897C(void *vm, void *task)
{
    func_02012374(func_02158F50(vm), task);
}
