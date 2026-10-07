/*
 * file:     unit_021D3B18_p02.c
 * unit:     yes
 * function: func_021D3DC0, func_021D40F4
 * address:  0x021D3DC0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   dat_021DE668  0x021DE668  data
 *   func_021D3D44 0x021D3D44  arm  ov016
 *   func_021D4148 0x021D4148  arm  ov016
 *   func_021D41F0 0x021D41F0  arm  ov016
 *   func_021D4214 0x021D4214  arm  ov016
 *   func_021D439C 0x021D439C  arm  ov016
 *   func_021D43C8 0x021D43C8  arm  ov016
 *   func_021D455C 0x021D455C  arm  ov016
 *   func_021D4574 0x021D4574  arm  ov016
 *   func_021D3250 0x021D3250  arm  ov016
 *   func_021D3AC8 0x021D3AC8  arm  ov016
 *   func_021D39C0 0x021D39C0  arm  ov016
 *   func_021F5F74 0x021F5F74  arm
 *   g_021DE668                       0x021DE668  data
 */
typedef struct Sub021D3DC0 {
    char _a90[0xa90];
    unsigned char state;
    char _a91[0xa98 - 0xa91];
    unsigned int f_a98;
    unsigned int f_a9c;
    char _aa0[0xaac - 0xaa0];
    unsigned char f_aac;
} Sub021D3DC0;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef struct {
    u8 pad0[0x648];
    u16 moveid_tgid;
    u8 pad1[0xa90 - 0x64a];
    u8 mov_stt;
    u8 mov_stt_old;
    u8 pad2[0xaa0 - 0xa92];
    void *sChildInfo[1];
    u8 pad3[0xac8 - 0xaa4];
    u32 ggid;
} Wk;

extern int func_021D3D44(void);
extern void func_021D4148(void);
extern void func_021D41F0(void);
extern void func_021D4214(void);
extern void func_021D439C(void);
extern void func_021D43C8(void);
extern void func_021D455C(void);
extern int func_021D4574(void);
extern unsigned int func_021D3250(void);
extern int func_021D3AC8(void);
extern void func_021D39C0(void);
extern void func_021F5F74(void);
void func_021D3DC0(void);
void func_021D40F4(u8 *stt, u8 *change_f);
extern Sub021D3DC0 *dat_021DE668;
extern Wk *g_021DE668;


/*
 * State tick for the object pointed to by 0x021DE668: dispatch on its byte
 * state at +0xa90 (table 0..0x22) and advance the +0xa9c delay counter /
 * +0xa98 frame counter, calling the per-state helper.  Addresses are
 * Black-image addresses.
 */
void func_021D3DC0(void)
{
    switch (dat_021DE668->state) {
    case 1:
        if (dat_021DE668->f_aac == 1) {
            dat_021DE668->f_aac = 0;
            func_021D3D44();
            return;
        }
        if (dat_021DE668->f_aac == 2) {
            dat_021DE668->f_aac = 0;
            dat_021DE668->state = 0x22;
        }
        return;
    case 2:
        func_021D4148();
        return;
    case 3:
        func_021D41F0();
        dat_021DE668->state = 4;
        return;
    case 4:
        dat_021DE668->f_a98++;
        func_021D4214();
        return;
    case 5:
    case 6:
        func_021D4214();
        return;
    case 7:
        func_021D439C();
        return;
    case 8:
    case 9:
    case 10:
        func_021D43C8();
        return;
    case 11:
        func_021D455C();
        return;
    case 16:
        dat_021DE668->f_a9c = 0;
        dat_021DE668->state = 0x11;
        return;
    case 17:
        if (dat_021DE668->f_a9c++ <= 0x1e)
            return;
        func_021D4574();
        return;
    case 18:
        func_021F5F74();
        dat_021DE668->f_a9c = 0;
        dat_021DE668->state = 0x16;
        return;
    case 19:
        if (dat_021DE668->f_a9c++ <= 0x1e)
            return;
        if (func_021D3250() != 1)
            return;
        func_021D3AC8();
        dat_021DE668->state = 0x14;
        return;
    case 21:
        func_021D39C0();
        dat_021DE668->f_a9c = 0;
        dat_021DE668->state = 0x16;
        return;
    case 22:
        if (dat_021DE668->f_a9c++ <= 0x1e)
            return;
        if (func_021D3250() != 1)
            return;
        func_021D3AC8();
        dat_021DE668->state = 0x17;
        return;
    case 24:
        func_021D39C0();
        dat_021DE668->f_a9c = 0;
        dat_021DE668->state = 0x19;
        return;
    case 25:
        if (dat_021DE668->f_a9c++ <= 0x1e)
            return;
        if (func_021D3250() != 1)
            return;
        func_021D3AC8();
        dat_021DE668->state = 0x1a;
        return;
    case 27:
        func_021D39C0();
        dat_021DE668->f_a9c = 0;
        dat_021DE668->state = 0x1c;
        return;
    case 28:
        if (dat_021DE668->f_a9c++ <= 0x1e)
            return;
        if (func_021D3250() == 1) {
            func_021D3AC8();
            dat_021DE668->state = 0x1d;
            return;
        }
        if (dat_021DE668->f_a9c % 30 != 1)
            return;
        if (dat_021DE668->f_a9c <= 0x37)
            return;
        func_021D39C0();
        return;
    case 32:
        func_021D39C0();
        dat_021DE668->f_a9c = 0;
        dat_021DE668->state = 0x21;
        return;
    case 33:
        if (dat_021DE668->f_a9c++ <= 0x1e)
            return;
        if (func_021D3250() != 1)
            return;
        func_021D3AC8();
        dat_021DE668->state = 0x22;
        return;
    case 30:
        func_021D39C0();
        return;
    case 0x22:
        return;
    }
    return;
}

/*
 * sdk:      DWCi_MOVGetStatus (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 */
void func_021D40F4(u8 *stt, u8 *change_f)
{
    *stt = g_021DE668->mov_stt;
    if (g_021DE668->mov_stt != g_021DE668->mov_stt_old)
        *change_f = 1;
    else
        *change_f = 0;
    g_021DE668->mov_stt_old = g_021DE668->mov_stt;
}
