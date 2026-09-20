/*
 * function: func_0200567C
 * address:  0x0200567C
 * packet:   pkt_0200567C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * blocker:  02050A70
 * symbols:
 *   g_020AA194      0x020AA194  data
 */

typedef struct { char pad[0xc]; int f0c; char *f10; } G;
extern G g_020AA194;
extern int func_02030D28(int);
extern int func_020419E4(int);
extern int func_02050A70(int);
extern int func_0204E638(int);
void func_0200567C(void)
{
    func_0204E638(func_02050A70(func_020419E4(func_02030D28(*(int *)(g_020AA194.f10 + 0x20)))));
    g_020AA194.f0c++;
}
