/*
 * function: MUSICAL_STAGE_SYS_Exit
 * address:  0x02156EDC
 * packet:   pkt_ov010_02156EDC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MUSICAL_PROGRAM_Delete  0x0215716C  thumb
 *   func_021F6888  0x021F6888  thumb
 *   func_020306F0  0x020306F0  arm
 *   MUSICAL_STAGE_SYS_Delete  0x02156F98  thumb
 *   func_02034A5C  0x02034A5C  arm
 *   func_020315D4  0x020315D4  arm
 *   ov112_id       0x00000070  data
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Ctx {
    u8 pad00[8];
    int *f08;
    u8 pad0c[8];
    void *f14;
    void *f18;
} Ctx;

extern void MUSICAL_PROGRAM_Delete(void *);
extern void func_021F6888(void *);
extern void func_020306F0(unsigned int);
struct Stage;
extern void MUSICAL_STAGE_SYS_Delete(struct Stage *s);
typedef signed int     s32;
struct S020315D4;
extern void func_02034A5C(s32 handle);
extern void func_020315D4(struct S020315D4 *p);
extern char ov112_id[];

int MUSICAL_STAGE_SYS_Exit(void *a, int b, int c, Ctx **d)
{
    if (c == 0) {
        MUSICAL_PROGRAM_Delete((*d)->f14);
        func_021F6888((*d)->f18);
        func_020306F0(0x2c);
        *(*d)->f08 = 2;
        MUSICAL_STAGE_SYS_Delete((struct Stage *)(*d));
        func_02034A5C((u32)ov112_id);
    }
    func_020315D4(a);
    func_020306F0(0x2e);
    return 1;
}
