/*
 * function: func_021C2FA0
 * address:  0x021C2FA0
 * packet:   pkt_ov016_021C2FA0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a(sceneoptmenu.o))
 *
 * symbols:
 *   func_021D5580 0x021D5580 arm ov016
 *   func_021BCB58 0x021BCB58 arm ov016
 *   func_021D6F38 0x021D6F38 arm ov016
 *   func_021BD5A8 0x021BD5A8 arm ov016
 *   func_021BD138 0x021BD138 arm ov016
 *   func_021D4C68 0x021D4C68 arm ov016
 *   func_021D6090 0x021D6090 arm ov016
 *   func_021C0E50 0x021C0E50 arm ov016
 *   func_021C0E40 0x021C0E40 arm ov016
 *   func_021C1984 0x021C1984 arm ov016
 *   func_021C255C 0x021C255C arm ov016
 *   func_021C1F1C 0x021C1F1C arm ov016
 *   func_021C3824 0x021C3824 arm ov016
 *   g_021DE5A8 0x021DE5A8 data
 */

typedef unsigned char u8;

typedef struct {
    u8 pos;
    u8 flag;
    char pad2[2];
    void *file;
    void *obj;
} Focus;

extern Focus g_021DE5A8;

extern int func_021D5580(int lcd);
extern int func_021BCB58(void);
extern void func_021D6F38(void *obj);
extern void func_021BD5A8(void);
extern int func_021BD138(void);
extern void func_021D4C68(void *file);
extern void func_021D6090(int lcd, int plane);
extern void func_021C0E50(void *param0, void *param1);
extern void func_021C0E40(void (*scene)());
extern void func_021C1984();
extern void func_021C255C();
extern void func_021C1F1C();
extern void func_021C3824();

void func_021C2FA0(void)
{
    if (func_021D5580(1))
        return;
    if (func_021D5580(0))
        return;
    if (!func_021BCB58())
        return;
    func_021D6F38(g_021DE5A8.obj);
    func_021BD5A8();
    func_021BD138();
    func_021D4C68(g_021DE5A8.file);
    func_021D6090(1, 1);
    func_021D6090(0, 0x14);
    if (g_021DE5A8.flag == 0) {
        func_021C0E50(0, 0);
        func_021C0E40(func_021C1984);
        return;
    }
    switch (g_021DE5A8.pos) {
    case 0:
        func_021C0E50(0, (void *)1);
        func_021C0E40(func_021C255C);
        return;
    case 1:
        func_021C0E50(0, (void *)1);
        func_021C0E40(func_021C1F1C);
        return;
    case 2:
        func_021C0E50(0, (void *)1);
        func_021C0E40(func_021C3824);
        return;
    }
}
