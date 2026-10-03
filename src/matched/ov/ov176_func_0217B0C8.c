/*
 * function: func_0217B0C8
 * address: 0x0217B0C8
 * packet: pkt_ov176_0217B0C8
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0217B2E4 0x0217B2E4 thumb ov176
 *   func_0217B35C 0x0217B35C thumb ov176
 *   func_0217B368 0x0217B368 thumb ov176
 *   func_0217B344 0x0217B344 thumb ov176
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_0217B064 0x0217B064 thumb ov176
 *   func_0217B1BC 0x0217B1BC thumb ov176
 */
typedef struct Data { unsigned words[8]; } Data;
extern void func_02082BCC(void *,int,unsigned);
extern void *func_0217B2E4(const Data *,unsigned);
extern void func_0217B35C(int *);
extern int func_0217B368(int *);
extern void func_0217B344(int *);
extern void func_021E8AA0(int *,int);
extern void func_0217B064(void *,int *,char *);
extern void func_0217B1BC(int *,int *,int *);
void func_0217B0C8(int *a,int *state,int *p)
{
    Data config;
    switch(*state) {
    case 0:
        func_02082BCC(&config,0,32);
        config.words[1]=p[2];
        config.words[2]=p[3];
        config.words[3]=p[4];
        config.words[4]=p[5];
        config.words[5]=p[8];
        config.words[6]=p[9];
        config.words[7]=*(unsigned *)p[10];
        if(p[12]!=0) {p[12]=0;config.words[0]=2;}
        else {
            switch(((int *)p[10])[1]) {
            case 0: config.words[0]=0;break;
            case 1: config.words[0]=1;break;
            }
        }
        p[11]=(int)func_0217B2E4(&config,78);
        (*state)++;
        break;
    case 1:
        func_0217B35C((int *)p[11]);
        switch(func_0217B368((int *)p[11])) {
        case 1: ((int *)p[10])[2]=0;*state=2;break;
        case 2: ((int *)p[10])[2]=1;*state=2;break;
        case 3: ((int *)p[10])[1]=3;*state=3;break;
        }
        break;
    case 2:
        func_0217B344((int *)p[11]);
        func_021E8AA0(a,(int)func_0217B064);
        break;
    case 3:
        func_0217B344((int *)p[11]);
        func_021E8AA0(a,(int)func_0217B1BC);
        break;
    }
}
