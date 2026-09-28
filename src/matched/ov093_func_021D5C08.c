/*
 * function: func_021D5C08
 * address:  0x021D5C08
 * packet:   pkt_ov093_021D5C08
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   data_021F040C  0x021F040C  data  ov093
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct UtilEntry {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    u16 f4;
    u16 f6;
    u8 f8;
    u8 f9;
    u16 fA;
    u8 fC;
    u8 fD;
};

struct UtilWork {
    void *f0;
    u8 pad4[0x100];
    struct UtilEntry e[4];
    u8 pad13C[4];
    u8 n140;
    u8 pad141[3];
    u8 f144;
    u8 pad145[5];
    u16 f14A;
    u16 f14C;
    u16 f14E;
    u8 pad150[3];
    u8 bits153[2];
    u8 bits155[2];
    u8 f157[5];
};

extern const u32 data_021F040C[4];
extern int func_021D5BDC(struct UtilWork *p, u32 n);

u32 func_021D5C08(struct UtilWork *p)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        if (func_021D5BDC(p, data_021F040C[i])) return data_021F040C[i];
    }
    return 0x10;
}
