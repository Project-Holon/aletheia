/*
 * function: SHINKA_CHECK_CheckEvolution
 * address:  0x0201B2B0
 * packet:   pkt_0201B038
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     wave 18 (2026-09-24): EXACT* (the listing extent includes the
 *           12-byte unlabelled follower at 0x0201B70C, src/matched/
 *           unit_0201B70C.c).  Closed by the heap id's width: the seventh
 *           parameter is a u16 and func_02020FE4 takes its third argument
 *           as a u16.  With both u32 the gate's `ldr r2, [sp, #0x68]` is
 *           hoisted above the pidHigh store (12 bytes out); u16 on the
 *           parameter alone breaks the size, u16 on both keeps the load
 *           behind the store as in the image.  func_02020FE4 masks the id to
 *           fifteen bits and ORs in 0x8000 (a temporary-heap id), and
 *           src/matched/unit_02007CB0.c already declares that parameter u16.
 *
 * symbols:
 *   func_02017E1C   0x02017E1C  thumb
 *   func_02020FE4   0x02020FE4  thumb
 *   func_02030734   0x02030734  arm
 *   func_020307B0   0x020307B0  arm
 *   SHINKA_CHECK_LoadData    0x0201B764  thumb
 *   SHINKA_CHECK_KnowsMove    0x0201B774  thumb
 *   POKEPARTY_HasSpecies    0x0201AC44  thumb
 *   TIMEZONE_IsNight   0x02011410  thumb
 *   _s32_div_f      0x0209C0A4  arm
 *   shinka_check_File 0x020A7330 data  a1
 *   _IceRockZones      0x020A7320  data  a2
 *   _MossRockZones      0x020A7322  data  a2
 *   _MagneticZones      0x020A7324  data  a2
 *   _ExtraEvolutionZones      0x020A732A  data  a2
 *
 * shinka_check.c (the string at 0x020A7330), the evolution checker: the
 * egg/everstone gate, then the 0x2A-byte evolution record (seven six-byte
 * rows, SHINKA_CHECK_LoadData) walked under a switch on the context (0 level up,
 * 1 trade, 2 and 3 item use); the first row that fires gives the target
 * species and its method goes to *methodOut (method 15 writes 15 and gives
 * no species).  docs/notes/SHINKA_CHECK_CheckEvolution.c.txt holds the method map and the
 * history.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SHINKA_CHECK_CheckEvolution.c \
 *       --func SHINKA_CHECK_CheckEvolution --addr 0x0201B2B0 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct EvoRow {
    u16 method;
    u16 param;
    u16 target;
};

extern u32   func_02017E1C(void *mon, u32 id, u32 v);
extern u32   func_02020FE4(u32 id, u32 sel, u16 heap);
extern void *func_02030734(u32 heap, u32 size, int c, const char *file, u16 line);
extern u32 func_020307B0(void *p);
struct Rec;
extern void SHINKA_CHECK_LoadData(u32 id, void *dest);
extern u32   SHINKA_CHECK_KnowsMove(void *mon, u32 move);
extern u32 POKEPARTY_HasSpecies(struct Rec *p, u32 target);
extern u32   TIMEZONE_IsNight(u32 tz);

extern u8 shinka_check_File[];
extern const u16 _IceRockZones[1];
extern const u16 _MossRockZones[1];
extern const u16 _MagneticZones[3];
extern const u16 _ExtraEvolutionZones[3];

u32 SHINKA_CHECK_CheckEvolution(void *party, void *mon, u32 context, u32 param,
                 u8 timezone, u32 *methodOut, u16 heap)
{
    u32 dummy;
    u32 a3c;
    u32 a38;
    u32 a34;
    u32 pid;
    struct EvoRow *table;
    u16 species;
    u16 held;
    u16 friendship;
    u16 pidHigh;
    u8  level;
    u8  beauty;
    int i;
    u16 result;
    u8  holdEffect;
    struct EvoRow *row;
    u32 j;

    result = 0;
    if (func_02017E1C(mon, 0x4C, 0) != 0) {
        return result;
    }
    species = func_02017E1C(mon, 5, 0);
    held = func_02017E1C(mon, 6, 0);
    pid = func_02017E1C(mon, 0, 0);
    beauty = func_02017E1C(mon, 0x14, 0);
    pidHigh = (pid & 0xFFFF0000) >> 16;
    holdEffect = func_02020FE4(held, 1, heap);
    if (species != 0x40 && holdEffect == 0x40 && context != 3) {
        return result;
    }
    if (methodOut == 0) {
        methodOut = &dummy;
    }
    i = 0;
    table = func_02030734(heap, 0x2A, 0, (const char *)shinka_check_File, 0x6A);
    SHINKA_CHECK_LoadData(species, table);

    switch (context) {
    case 0:
        level = func_02017E1C(mon, 0x9E, i);
        friendship = func_02017E1C(mon, 9, i);
        for (i = 0; i < 7; i++) {
            row = &table[i];
            switch (row->method) {
            case 1:
                if (friendship >= 220) {
                    result = row->target;
                }
                break;
            case 2:
                if (TIMEZONE_IsNight(timezone) == 0 && friendship >= 220) {
                    result = row->target;
                }
                break;
            case 3:
                if (TIMEZONE_IsNight(timezone) == 1 && friendship >= 220) {
                    result = row->target;
                }
                break;
            case 4:
                if (row->param <= level) {
                    result = row->target;
                }
                break;
            case 9:
                if (row->param <= level) {
                    a34 = func_02017E1C(mon, 0xA2, 0);
                    if (a34 > func_02017E1C(mon, 0xA3, 0)) {
                        result = row->target;
                    }
                }
                break;
            case 10:
                if (row->param <= level) {
                    a38 = func_02017E1C(mon, 0xA2, 0);
                    if (a38 == func_02017E1C(mon, 0xA3, 0)) {
                        result = row->target;
                    }
                }
                break;
            case 11:
                if (row->param <= level) {
                    a3c = func_02017E1C(mon, 0xA2, 0);
                    if (a3c < func_02017E1C(mon, 0xA3, 0)) {
                        result = row->target;
                    }
                }
                break;
            case 12:
                if (row->param <= level && pidHigh % 10 < 5) {
                    result = row->target;
                }
                break;
            case 13:
                if (row->param <= level && pidHigh % 10 >= 5) {
                    result = row->target;
                }
                break;
            case 14:
                if (row->param <= level) {
                    result = row->target;
                }
                break;
            case 15:
                *methodOut = 15;
                break;
            case 16:
                if (row->param <= beauty) {
                    result = row->target;
                }
                break;
            case 19:
                if (TIMEZONE_IsNight(timezone) == 0 && held == row->param) {
                    result = row->target;
                }
                break;
            case 20:
                if (TIMEZONE_IsNight(timezone) == 1 && held == row->param) {
                    result = row->target;
                }
                break;
            case 21:
                if (SHINKA_CHECK_KnowsMove(mon, row->param) == 1) {
                    result = row->target;
                }
                break;
            case 22:
                if (party != 0 && POKEPARTY_HasSpecies(party, row->param) == 1) {
                    result = row->target;
                }
                break;
            case 23:
                if (func_02017E1C(mon, 0x6E, 0) == 0 && row->param <= level) {
                    result = row->target;
                }
                break;
            case 24:
                if (func_02017E1C(mon, 0x6E, 0) == 1 && row->param <= level) {
                    result = row->target;
                }
                break;
            case 25:
                for (j = 0; j < 3; j++) {
                    if (param == _MagneticZones[j]) {
                        result = row->target;
                        break;
                    }
                }
                break;
            case 26:
                for (j = 0; j < 1; j++) {
                    if (param == _MossRockZones[j]) {
                        result = row->target;
                        break;
                    }
                }
                break;
            case 27:
                for (j = 0; j < 1; j++) {
                    if (param == _IceRockZones[j]) {
                        result = row->target;
                        break;
                    }
                }
                break;
            case 28:
                for (j = 0; j < 3; j++) {
                    if (param == _ExtraEvolutionZones[j]) {
                        result = row->target;
                        break;
                    }
                }
                break;
            }
            if (result != 0) {
                *methodOut = row->method;
                break;
            }
        }
        break;
    case 1:
        for (i = 0; i < 7; i++) {
            row = &table[i];
            switch (row->method) {
            case 5:
                result = row->target;
                break;
            case 6:
                if (held == row->param) {
                    result = row->target;
                }
                break;
            case 7:
                if (func_02020FE4((u16)func_02017E1C((void *)param, 6, 0), 1, heap) != 0x40) {
                    if ((func_02017E1C(mon, 0xAB, 0) == 588
                         && func_02017E1C((void *)param, 0xAB, 0) == 616)
                     || (func_02017E1C((void *)param, 0xAB, 0) == 588
                         && func_02017E1C(mon, 0xAB, 0) == 616)) {
                        result = row->target;
                    }
                }
                break;
            }
            if (result != 0) {
                *methodOut = row->method;
                break;
            }
        }
        break;
    case 2:
    case 3:
        for (i = 0; i < 7; i++) {
            row = &table[i];
            if (row->method == 8 && param == row->param) {
                result = row->target;
            }
            if (row->method == 0x11 && func_02017E1C(mon, 0x6E, 0) == 0 && param == row->param) {
                result = row->target;
            }
            if (row->method == 0x12 && func_02017E1C(mon, 0x6E, 0) == 1 && param == row->param) {
                result = row->target;
            }
            if (result != 0) {
                *methodOut = row->method;
                break;
            }
        }
        break;
    }
    func_020307B0(table);
    return result;
}

