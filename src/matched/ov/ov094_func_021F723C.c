/*
 * function: func_021F723C
 * address: 0x021F723C
 * packet: pkt_ov094_021F723C
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F9220 0x021F9220 thumb ov094
 *   func_021F9260 0x021F9260 thumb ov094
 *   func_02048AFC 0x02048AFC arm
 *   func_02048B44 0x02048B44 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_021F73A4 0x021F73A4 thumb ov094
 */
extern void func_021F9220(int *, int *, int *, int *);
extern int func_021F9260(void *, void *);
extern void func_02048AFC(int, int *);
extern void func_02048B44(int, int *);
struct Light;
extern void func_02048AD0(struct Light *l);
extern void func_021F73A4(int *);

void func_021F723C(int *p)
{
    int a[3];
    int b[3];
    int ret = 1;
    int n;
    if (p[5] == 0) return;
    if (p[27] == 0) {
        p[27] = p[28];
        if (p[29] != 0) {
            if (--p[29] == 0) {
                n = p[18] >> 1; if (n) p[18] = n;
                n = p[19] >> 1; if (n) p[19] = n;
                n = p[20] >> 1; if (n) p[20] = n;
                n = p[21] >> 1; if (n) p[21] = n;
                n = p[22] >> 1; if (n) p[22] = n;
                n = p[23] >> 1; if (n) p[23] = n;
            }
        }
        if (p[5] & 1) {
            func_021F9220(&p[6], &p[18], &p[12], &ret);
            func_021F9220(&p[7], &p[19], &p[13], &ret);
            func_021F9220(&p[8], &p[20], &p[14], &ret);
            if (ret == 1) p[5] &= ~1;
        }
        if (p[5] & 2) {
            func_021F9220(&p[9], &p[21], &p[15], &ret);
            func_021F9220(&p[10], &p[22], &p[16], &ret);
            func_021F9220(&p[11], &p[23], &p[17], &ret);
            if (ret == 1) p[5] &= ~2;
        }
        if (p[5] & 4) {
            ret = func_021F9260(&p[30], &p[24]);
            if (ret == 1) p[5] &= ~4;
        }
        a[0] = p[6] + p[24];
        a[1] = p[7] + p[25];
        a[2] = p[8] + p[26];
        b[0] = p[9] + p[24];
        b[1] = p[10] + p[25];
        b[2] = p[11] + p[26];
        func_02048AFC(p[1], a);
        func_02048B44(p[1], b);
        func_02048AD0((struct Light *)p[1]);
        func_021F73A4(p);
    } else {
        p[27]--;
    }
}
