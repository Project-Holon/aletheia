/*
 * function: func_021C78A0
 * address:  0x021C78A0
 * packet:   pkt_ov016_021C78A0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      drawAddress (libdwcutil.TWL.HYB.a sceneseteditaddress.o)
 *
 * symbols:
 *   func_021D5F14  0x021D5F14  arm  ov016
 *   func_021D5E5C  0x021D5E5C  arm  ov016
 *   func_021D5FC4  0x021D5FC4  arm  ov016
 *   g_021DE5E4     0x021DE5E4  data
 *   g_021DA5E8     0x021DA5E8  data
 *   g_021DA5D4     0x021DA5D4  data
 */

typedef struct COORD {
    unsigned short x, y;
} COORD;

typedef struct AREA {
    unsigned short x, y, w, h;
} AREA;

typedef struct MemSsea {
    int bg;
    unsigned char pad0[4];
    unsigned char text[12];
} MemSsea;

extern void func_021D5F14();
extern void func_021D5E5C();
extern void func_021D5FC4();
extern MemSsea *g_021DE5E4;
extern COORD g_021DA5E8;
extern unsigned char g_021DA5D4[];

void func_021C78A0(void)
{
    AREA a;
    int i;
    unsigned short buf[2];

    a.x = g_021DA5E8.x;
    a.y = g_021DA5E8.y;
    a.w = 11;
    a.h = 16;
    func_021D5F14(g_021DE5E4->bg, 0);
    buf[1] = 0;
    for (i = 0; i < 12; i++) {
        buf[0] = g_021DE5E4->text[i];
        a.x = g_021DA5D4[i];
        func_021D5E5C(g_021DE5E4->bg, a.x, a.y, a.w, a.h, 2, 0x480, buf);
    }
    func_021D5FC4(g_021DE5E4->bg);

}
