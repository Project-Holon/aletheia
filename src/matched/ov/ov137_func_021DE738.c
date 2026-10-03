/*
 * function: func_021DE738
 * address: 0x021DE738
 * packet: pkt_ov137_021DE738
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: previous state at +0x4804 is read at 0x021DE764 and 0x021DE7CA.
 * symbols:
 *   func_021DE354 0x021DE354 thumb ov137
 *   func_021DCF50 0x021DCF50 thumb ov137
 *   func_02184114 0x02184114 thumb ov022
 *   func_021841A4 0x021841A4 thumb ov022
 *   func_021841A0 0x021841A0 thumb ov022
 */
typedef unsigned char u8;
typedef struct { u8 pad[0x4804]; volatile int previous; } Obj;
extern int func_021DE354(void *);
extern void *func_021DCF50(u8 *p);
extern int func_02184114(unsigned char *p);
extern unsigned func_021841A4(void *);
extern unsigned char func_021841A0(unsigned char *p);
extern void func_0201FEF4(u8 *o);
int func_021DE738(Obj *obj)
{
    u8 *p = (u8 *)obj;
    int state;
    state = func_021DE354(p);
    if (state > *(int *)(*(u8 **)(p + 16) + 44)) {
        if (func_02184114(func_021DCF50(p))) *(int *)(p + 0x4808) = 1;
    } else *(int *)(p + 0x4808) = 0;
    if (state == obj->previous) return 1;
    switch (state) {
    case 0: break;
    case 1:
        if (func_021841A4(func_021DCF50(p)) > 1 || func_021841A0(func_021DCF50(p)) > 1) return 1;
        *(int *)(p + 0x118) = 17;
        if (*(void **)(p + 0xe8)) {
            func_0201FEF4(*(void **)(p + 0xe8));
            *(void **)(p + 0xe8) = 0;
        }
        return 2;
    case 2: case 3: case 4:
        if (state < obj->previous)
            *(int *)(*(u8 **)(p + 16) + 44) = func_021841A4(func_021DCF50(p));
        break;
    case 5: break;
    }
    obj->previous = func_021DE354(p);
    return 1;
}
