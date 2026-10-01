/*
 * function: func_0217B594
 * address: 0x0217B594
 * packet: pkt_ov176_0217B594
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0217D398 0x0217D398 thumb ov176
 *   func_0217D434 0x0217D434 thumb ov176
 *   func_0217D44C 0x0217D44C thumb ov176
 *   func_0217D410 0x0217D410 thumb ov176
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_0217B4A0 0x0217B4A0 thumb ov176
 */
typedef struct { int mode; int a,b,c,d,e,f,g; } Config;
extern void func_02082BCC(void *,int,int);
extern int func_0217D398(Config *,int);
extern void func_0217D434(int);
extern int func_0217D44C(int);
extern void func_0217D410(int);
extern void func_021E8AA0(int,int);
extern void func_0217B4A0(void);
void func_0217B594(int p, int *state, char *q)
{
    Config config;
    switch (*state) {
    case 0:
        func_02082BCC(&config, 0, 32);
        config.mode = 0;
        config.a = *(int *)(q + 24);
        config.b = *(int *)(q + 28);
        config.c = *(int *)(q + 32);
        config.d = *(int *)(q + 36);
        config.e = *(int *)(q + 40);
        config.f = *(int *)(q + 44);
        config.g = *(int *)(q + 48);
        *(int *)(q + 56) = func_0217D398(&config, *(unsigned short *)(q + 52));
        (*state)++;
        break;
    case 1:
        func_0217D434(*(int *)(q + 56));
        if (func_0217D44C(*(int *)(q + 56))) (*state)++;
        break;
    case 2:
        func_0217D410(*(int *)(q + 56));
        func_021E8AA0(p, (int)func_0217B4A0);
        break;
    }
}
