/*
 * function: func_021FE594
 * address: 0x021FE594
 * packet: pkt_ov094_021FE594
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two zero alignment bytes at 0x021FE68E.
 * symbols:
 *   _fflt 0x0209BDBC arm
 *   _ffix 0x0209C494 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   func_02006138 0x02006138 thumb
 *   func_02006268 0x02006268 thumb
 *   func_02072F34 0x02072F34 arm
 *   func_021F89BC 0x021F89BC thumb ov094
 */
extern float _fflt(int);
extern float _fadd(float, float);
extern float _fsub(float, float);
extern int _ffix(float);
extern unsigned int *func_02006138(int i);
typedef unsigned int   u32;
extern void func_02006268(int i, u32 a, u32 b, u32 c);
extern void func_02072F34(char *, unsigned int);
extern void func_021F89BC(void *);
void func_021FE594(void *h, int *s)
{
    int done;
    int v;
    done = 0;
    if (s[8] != 0) {
        s[8]--;
        return;
    }
    if (s[11] == 0) {
        s[11] = s[12];
        s[6] += s[7];
        v = s[6] >> 12;
        if (s[13] & 1) {
            if (s[7] < 0) {
                if (v < s[4])
                    v = s[4];
            } else {
                if (v > s[4])
                    v = s[4];
            }
        } else {
            if (s[7] < 0) {
                if (v < s[5])
                    v = s[5];
            } else {
                if (v > s[5])
                    v = s[5];
            }
        }
        if (v > 0)
            s[6] = _ffix(_fadd(0.5f, _fflt(v << 12)));
        else
            s[6] = _ffix(_fsub(_fflt(v << 12), 0.5f));
        switch (s[3]) {
        case 0: func_02006268(s[1], -1, v, -1); break;
        case 1: func_02072F34((char *)func_02006138(s[1]), v); break;
        case 2: func_02006268(s[1], -1, -1, v); break;
        }
        if (s[9] == 0) {
            s[9] = s[10];
            switch (s[2]) {
            case 0: done = 1; break;
            case 1:
                s[13]--;
                if (s[13] != 0)
                    s[7] *= -1;
                else
                    done = 1;
                break;
            }
        } else {
            s[9]--;
        }
    } else {
        s[11]--;
    }
    if (done == 1)
        func_021F89BC(h);
}
