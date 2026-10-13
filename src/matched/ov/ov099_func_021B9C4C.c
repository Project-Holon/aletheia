/*
 * function: WIFICLUBACTOR_ProcessSpawnCommands
 * address:  0x021B9C4C
 * packet:   pkt_ov099_021BF2C4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C48D4  0x021C48D4  thumb  ov127
 *   func_021C5370  0x021C5370  thumb  ov127
 *   func_021C5F80  0x021C5F80  thumb  ov127
 */
typedef struct {
    char pad[0x588];
    void *f588;             /* 0x588 */
    void *f58c;             /* 0x58c */
    char pad590[0xc];
    void *f59c;             /* 0x59c */
} Work;

extern int func_021C5F80(void *q, int *out);
typedef unsigned char  u8;
extern int func_021C5370(void *a, void *b, const u8 *desc, int *out);
extern void func_021C48D4(void *a, u8 *q);

void WIFICLUBACTOR_ProcessSpawnCommands(Work *w)
{
    int a;
    int b[2];

    while (func_021C5F80(w->f59c, &a) == 1) {
        if (func_021C5370(w->f588, w->f58c, (const u8 *)(&a), b) == 1)
            func_021C48D4(w->f58c, (u8 *)b);
    }
}
