/*
 * function: func_021DE17C
 * address: 0x021DE17C
 * packet: pkt_ov137_021DE17C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DCF50 0x021DCF50 thumb ov137
 *   func_02184180 0x02184180 thumb ov022
 *   func_0201F02C 0x0201F02C thumb
 *   func_021841A4 0x021841A4 thumb ov022
 *   func_02039338 0x02039338 arm
 */
extern void *func_021DCF50(void *);
typedef unsigned short u16;
typedef unsigned int   u32;
struct WordSet;
extern char *func_02184180(unsigned char *p, int i);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern int func_021841A4(unsigned char *p);
extern u16 func_02039338(void);
void func_021DE17C(char *p, int command, int player) {
    void *target;
    if (*(int *)(p+0x118) == 3) {
        switch (command) {
        case 1:
            target = func_02184180(func_021DCF50(p), player);
            if (target != 0)
                func_0201F02C(*(void **)(p+0x3c), 0, target);
            *(int *)(p+0x118) = command;
            *(unsigned *)(*(char **)(p+0x10)+0x2c) = func_021841A4(func_021DCF50(p));
            *(unsigned *)(*(char **)(p+0x10)+0x30) = 0;
            return;
        case 19:
            func_0201F02C(*(void **)(p+0x3c), 0, func_02184180(func_021DCF50(p), player));
            if (player != func_02039338()) {
                if (func_02039338() == 0)
                    *(unsigned *)(*(char **)(p+0x10)+0x30) &= player ^ 0xffff;
                *(int *)(p+0x118) = command;
            }
            break;
        }
    } else {
        if (command == 1) {
            *(unsigned *)(*(char **)(p+0x10)+0x30) = 0;
            *(unsigned *)(*(char **)(p+0x10)+0x2c) = func_021841A4(func_021DCF50(p));
        }
    }
}
