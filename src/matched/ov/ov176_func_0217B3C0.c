/*
 * function: func_0217B3C0
 * address: 0x0217B3C0
 * packet: pkt_ov176_0217B3C0
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0217B93C 0x0217B93C thumb ov176
 *   func_0217B964 0x0217B964 thumb ov176
 *   func_0217B7D8 0x0217B7D8 thumb ov176
 *   func_0217B930 0x0217B930 thumb ov176
 *   func_0217B924 0x0217B924 thumb ov176
 *   func_0217B970 0x0217B970 thumb ov176
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_0217B4A0 0x0217B4A0 thumb ov176
 *   func_0217B6AC 0x0217B6AC thumb ov176
 *   func_0217B468 0x0217B468 thumb ov176
 */
extern void func_0217B93C(int *,int);
extern int func_0217B964(int *);
extern void func_0217B7D8(int *,int);
extern unsigned func_0217B930(int *);
extern void func_0217B924(int *);
extern void func_0217B970(int *,int);
extern void func_021E8AA0(int,int);
extern void func_0217B4A0(void);
extern void func_0217B6AC(void);
extern void func_0217B468(void);
void func_0217B3C0(int p, unsigned *state, int *q)
{
    unsigned result;
    switch (*state) {
    case 0: func_0217B93C(q,0); *state = 1; break;
    case 1: if (func_0217B964(q) == 1) *state = 2; break;
    case 2: func_0217B7D8(q,0); *state = 3; break;
    case 3:
        result = func_0217B930(q);
        if (result != -1) {
            switch (result) {
            case 0: func_021E8AA0(p,(int)func_0217B4A0); break;
            case 1: func_021E8AA0(p,(int)func_0217B6AC); break;
            case 2: func_021E8AA0(p,(int)func_0217B468); break;
            case 3: func_0217B970(q,1); break;
            }
            func_0217B924(q);
        }
        break;
    }
}
