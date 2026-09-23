/*
 * function: sub_0201B2B0
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
 *   sub_0201B764    0x0201B764  thumb
 *   sub_0201B774    0x0201B774  thumb
 *   sub_0201AC44    0x0201AC44  thumb
 *   func_02011410   0x02011410  thumb
 *   _s32_div_f      0x0209C0A4  arm
 *   s_shinka_check_c 0x020A7330 data  a1
 *   g_020A7320      0x020A7320  data  a2
 *   g_020A7322      0x020A7322  data  a2
 *   g_020A7324      0x020A7324  data  a2
 *   g_020A732A      0x020A732A  data  a2
 *
 * shinka_check.c (the string at 0x020A7330), the evolution checker: the
 * egg/everstone gate, then the 0x2A-byte evolution record (seven six-byte
 * rows, sub_0201B764) walked under a switch on the context (0 level up,
 * 1 trade, 2 and 3 item use); the first row that fires gives the target
 * species and its method goes to *methodOut (method 15 writes 15 and gives
 * no species).  docs/notes/sub_0201B2B0.c.txt holds the method map and the
 * history.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201B2B0.c \
 *       --func sub_0201B2B0 --addr 0x0201B2B0 --cc 1.1p1 --thumb
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
extern void *func_02030734(u32 heap, u32 size, u32 c, void *file, u32 line);
extern void  func_020307B0(void *p);
extern void  sub_0201B764(u32 species, struct EvoRow *table);
extern u32   sub_0201B774(void *mon, u32 move);
extern u32   sub_0201AC44(void *party, u32 species);
extern u32   func_02011410(u32 tz);

extern u8 s_shinka_check_c[];
extern const u16 g_020A7320[1];
extern const u16 g_020A7322[1];
extern const u16 g_020A7324[3];
extern const u16 g_020A732A[3];

u32 sub_0201B2B0(void *party, void *mon, u32 context, u32 param,
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
    table = func_02030734(heap, 0x2A, 0, s_shinka_check_c, 0x6A);
    sub_0201B764(species, table);

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
                if (func_02011410(timezone) == 0 && friendship >= 220) {
                    result = row->target;
                }
                break;
            case 3:
                if (func_02011410(timezone) == 1 && friendship >= 220) {
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
                if (func_02011410(timezone) == 0 && held == row->param) {
                    result = row->target;
                }
                break;
            case 20:
                if (func_02011410(timezone) == 1 && held == row->param) {
                    result = row->target;
                }
                break;
            case 21:
                if (sub_0201B774(mon, row->param) == 1) {
                    result = row->target;
                }
                break;
            case 22:
                if (party != 0 && sub_0201AC44(party, row->param) == 1) {
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
                    if (param == g_020A7324[j]) {
                        result = row->target;
                        break;
                    }
                }
                break;
            case 26:
                for (j = 0; j < 1; j++) {
                    if (param == g_020A7322[j]) {
                        result = row->target;
                        break;
                    }
                }
                break;
            case 27:
                for (j = 0; j < 1; j++) {
                    if (param == g_020A7320[j]) {
                        result = row->target;
                        break;
                    }
                }
                break;
            case 28:
                for (j = 0; j < 3; j++) {
                    if (param == g_020A732A[j]) {
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

