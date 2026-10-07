/*
 * file:     btl_calc_p08.c
 * unit:     yes
 * function: func_021D74E4, func_021D74F8, func_021D7540, func_021D75A8
 * address:  0x021D74E4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D74C8   0x021D74C8  thumb
 *   g_021F3ECC     0x021F3ECC  data
 *   data_021F3AB4  0x021F3AB4  data
 *   func_02034714  0x02034714  arm
 *   func_021D77C4  0x021D77C4  thumb  ov093
 */
#include "../../matched/include/G_Tbl.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct {
    u32 count;
    u16 keys[0x60];
    u32 vals[0x60];
    u32 a[0x60];
    u32 b[0x60];
    u8 c[0x60];
} Tbl;

extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_021D77C4(Tbl *p, int key);
/* 021D74E4 call through a global pointer when it is set */ void func_021D74E4(void);
void func_021D74F8(int line);
void func_021D7540(int line);
void func_021D75A8(int key, u32 val);
extern struct Tbl g_021F3ECC;
extern char data_021F3AB4[];


/* 021D74E4  call through a global pointer when it is set */
/*
 * 7 instructions, 16 bytes: push {r3, lr}; ldr r0, pool_021D74F4; ldr r0, [r0]; cmp r0, #0; beq loc_021D74F2; bl func_021D74C8; pop {r3, pc}.
 */
void func_021D74E4(void)
{
    u32 g = *(u32 *)0x021F3ECC;
    if (g != 0)
        func_021D74C8(g);
}


void func_021D74F8(int line)
{
    Tbl *p = ((Tbl *)&g_021F3ECC);
    while (p->count < 0x60) {
        if (p->keys[p->count] == 0) break;
        p->count++;
    }
    if (p->count < 0x5F) {
        p->keys[p->count++] = 1;
    } else {
        func_02034714(data_021F3AB4, 0, data_021F3AB4);
    }
}

void func_021D7540(int line)
{
    Tbl *p = ((Tbl *)&g_021F3ECC);
    u16 i;
    if (p->count != 0) {
        i = p->count;
        while (i < 0x60 && p->keys[i] != 0) {
            p->keys[i++] = 0;
        }
        p->count--;
        p->keys[p->count] = 0;
        if (p->count != 0) {
            while (p->count != 0) {
                p->count--;
                if (p->keys[p->count] == 1) {
                    p->count++;
                    return;
                }
            }
        }
    }
}


void func_021D75A8(int key, u32 val)
{
    u32 i = func_021D77C4(((Tbl *)&g_021F3ECC), key);
    g_021F3ECC.keys[i] = key;
    g_021F3ECC.vals[i] = val;
    g_021F3ECC.b[i] = 0;
    g_021F3ECC.a[i] = 0;
    g_021F3ECC.c[i] = 0;
}
