/*
 * function: func_021F54CC
 * address: 0x021F54CC
 * packet: pkt_ov083_021F54CC
 * region: ov083
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: MATCH*
 * note 2026-10-05 (wave P22 lane 10): extent is 160 B (158 B code plus the
 *   trailing nop pad). Bytes equal to the listing in c99 and c. Only the two
 *   func_02190854 relocations lack a witness: filed the 12-byte ov021 leaf as
 *   src/matched/ov/ov021_func_02190854.c (EXACT). The lane tool does not see it
 *   until the integrator refreshes the manifest; then this should read EXACT.
 *   Callee arity: matched func_0219082C is int(u32,u32,u32,u32) and
 *   func_02190620 is int(u32,u32,u32,u32), but their callers pass one argument
 *   (r1-r3 are clobbered by func_02190854). Declared here with one parameter.
 *   Older draft (docs/notes/pkt_ov083_021F54CC.c.txt) had the same body; its
 *   blocker was the 4-parameter definition conflict.
 * symbols:
 *   func_02190FA0 0x02190FA0 thumb ov021
 *   func_0219103C 0x0219103C thumb ov021
 *   func_021910C0 0x021910C0 thumb ov021
 *   func_02191008 0x02191008 thumb ov021
 *   func_021907C4 0x021907C4 thumb ov021
 *   func_02190854 0x02190854 thumb ov021
 *   func_0219082C 0x0219082C thumb ov021
 *   func_021F55D4 0x021F55D4 thumb ov083
 *   func_021F5400 0x021F5400 thumb ov083
 *   func_020362DC 0x020362DC arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Fx;
extern void *func_02190FA0(struct Fx *, u32, u32);
extern void func_0219103C(u32 *, u32, u32, u32);
extern u32 func_021910C0(u32 *);
extern int func_02191008(void *);
extern void *func_021907C4(struct Fx *, u32, u32, u32, u16, u16);
extern void func_02190854(void *);
extern int func_0219082C(void *);
extern void func_021F55D4(char *);
extern void func_021F5400(u8 *);
extern u32 func_020362DC(void);
int func_021F54CC(void *task, u32 *st, u8 *p) {
    void *v;
    switch (*st) {
    case 0:
        v = func_02190FA0(*(struct Fx **)(p+20),*(u32 *)(p+40),19);
        *(void **)(p+32) = v;
        func_0219103C(v,0,0,3);
        *st += 1;
        break;
    case 1:
        if (func_021910C0(*(u32 **)(p+32))) {
            func_02191008(*(void **)(p+32));
            *st += 1;
        }
        break;
    case 2:
        v = func_021907C4(*(struct Fx **)(p+20),*(u32 *)(p+40),4,1,24,22);
        *(void **)(p+24) = v;
        func_02190854(v);
        func_021F55D4((char *)p);
        *st += 1;
        break;
    case 3:
        if (func_020362DC() & 3) *st += 1;
        break;
    default:
        func_02190854(*(void **)(p+24));
        func_0219082C(*(void **)(p+24));
        func_021F5400(p);
        return 1;
    }
    return 0;
}
