/*
 * function: func_021EBA84
 * address:  0x021EBA84
 * packet:   pkt_ov170_021EBA84
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EAC98 0x021EAC98 thumb
 *   func_021EBA30 0x021EBA30 thumb
 *   func_021EAC28 0x021EAC28 thumb
 *   func_021EABA0 0x021EABA0 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_021EE0FC 0x021EE0FC thumb
 *
 * Prints message msg of the box-menu bank into message window i.
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern void *func_021EAC98(void);
extern void func_021EBA30(unsigned char *p, void *win);
extern void func_021EAC28(char *w, int i, void *bank, u32 idx, int x, int y, u32 font, u16 color);
extern void func_021EABA0(void **win);
extern void func_02045C04(void *bank);
extern void func_021EE0FC(unsigned char *p);

#define WORK(p) (*(char **)((p) + 0x2C))

void func_021EBA84(unsigned char *p, int msg, int i)
{
    void *bank = func_021EAC98();
    func_021EBA30(p, *(void **)(WORK(p) + i * 8 + 0x94));
    func_021EAC28(WORK(p), i, bank, msg, 0, 0, *(u32 *)(WORK(p) + 0x78), 0x44F);
    func_021EABA0((void **)(WORK(p) + 0x94 + i * 8));
    func_02045C04(bank);
    func_021EE0FC(p);
}
