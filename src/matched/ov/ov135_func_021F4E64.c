/*
 * function: func_021F4E64
 * address:  0x021F4E64
 * packet:   pkt_021F4E64
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
  *
  *
 * symbols:
 *   func_021F5060  0x021F5060  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

struct TaskMenu;
struct TaskMenuState;
extern void func_02027858(struct TaskMenu *m);
extern void func_02027FD8(struct TaskMenuState *s);
extern void func_021F5060(void);

void func_021F4E64(u8 *p)
{
    if (*(void **)(p + 0xE08) != 0) {
        func_02027858(*(void **)(p + 0xE08));
        *(void **)(p + 0xE08) = 0;
    }
    if (*(void **)(p + 0xE04) != 0) {
        func_02027FD8(*(void **)(p + 0xE04));
        *(void **)(p + 0xE04) = 0;
    }
    func_021F5060();
}
