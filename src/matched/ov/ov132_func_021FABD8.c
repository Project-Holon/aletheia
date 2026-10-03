/*
 * function: func_021FABD8
 * address: 0x021FABD8
 * packet: pkt_ov132_021FABD8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: two bytes of zero padding follow the epilogue before 021FAC74.
 * symbols:
 *   func_021F9E44 0x021F9E44 thumb ov132
 *   func_021FAD2C 0x021FAD2C thumb ov132
 *   func_020307B0 0x020307B0 arm
 *   func_02030D28 0x02030D28 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Ctx;
extern u32 func_021F9E44(u8 *p);
extern int func_021FAD2C(void *, char *);
extern void func_020307B0(void *);
extern void func_02030D28(struct Ctx *c);
void func_021FABD8(char *p)
{
    char **slot;
    u8 i;
    int ready;
    int count;
    ready = 1;
    count = func_021F9E44(*(void **)(p + 0x34));
    while (count != 0) {
        for (i = 0; i < 10; i++) {
            slot = (char **)(p + i * 4);
            if (slot[3] != 0) {
                if (func_021FAD2C(p, slot[3]) == 1) {
                    func_020307B0(slot[3]);
                    slot[3] = 0;
                } else {
                    if ((*(u16 *)(slot[3] + 0x16) & 2) && !(*(u16 *)(slot[3] + 0x16) & 4)) ready = 0;
                }
            }
        }
        if (ready == 1) {
            for (i = 0; i < 10; i++) {
                char *q;
                q = *(char **)(p + 0xc + i * 4);
                if (q != 0 && (*(u16 *)(q + 0x16) & 2) && (*(u16 *)(q + 0x16) & 4)) *(u16 *)(q + 0x16) ^= 4;
            }
        }
        func_02030D28(*(void **)(p + 4));
        count--;
    }
}
