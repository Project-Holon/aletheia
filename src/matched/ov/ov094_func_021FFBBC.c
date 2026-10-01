/*
 * function: func_021FFBBC
 * address: 0x021FFBBC
 * packet: pkt_ov094_021FFBBC
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 *
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 * blocker: ARM9 0x02016068 has no outside witness at all three call sites.
 * Verified scratch C, EXACT (blocker_02016068_r1.log):
 * typedef unsigned char u8;
 * typedef struct { char pad[0x140]; unsigned int padbits : 24; unsigned int value : 4; } Data;
 * u8 func_02016068(Data *p) { return p->value; }
 * symbols:
 *   func_022019F4 0x022019F4 thumb ov094
 *   func_02016068 0x02016068 thumb
 *   func_0220074C 0x0220074C thumb ov094
 *   func_021F935C 0x021F935C thumb ov094
 *   func_02201234 0x02201234 thumb ov094
 *   func_022012CC 0x022012CC thumb ov094
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
typedef unsigned char u8;
typedef struct { int x, y, z; } Vec;
extern int func_022019F4(char *p, int key);
extern u8 func_02016068(void *p);
extern void func_0220074C(void *, int, int, Vec *, Vec *, int, int, int, void *, void (*)(void *), int, u8);
extern int func_021F935C(int x);
extern void func_02201234(void);
extern void func_022012CC(void *p);
#define FX(x) ((int)(((x) > 0) ? ((float)((x) << 12) + .5f) : ((float)((x) << 12) - .5f)))
void func_021FFBBC(char *w, int key, int kind, int value, int a, int b, int c)
{
    int idx = func_022019F4(w, key);
    char *e;
    int off;
    Vec start, end;
    if (idx == -1)
        return;
    e = w + 8;
    off = idx * 0x5c;
    if (*(void **)(e + off) == 0)
        return;
    start.x = FX(func_02016068(*(void **)(e + off)));
    start.y = 0;
    start.z = 0;
    end.x = FX(value);
    end.y = 0;
    end.z = 0;
    (*(u8 *)(w + 0x5a4 + key))++;
    func_0220074C(w, key, kind, &start, &end, a, b, c, (void *)func_02201234, func_022012CC, 0, *(u8 *)(w + 0x5a4 + key));
    *(int *)(w + 0x530) |= func_021F935C(key);
}
