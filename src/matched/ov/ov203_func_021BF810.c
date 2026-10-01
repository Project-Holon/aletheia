/*
 * function: func_021BF810
 * address: 0x021BF810
 * packet: pkt_ov203_021BF810
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BE9A4 0x021BE9A4 thumb ov203
 *   func_021BF9B8 0x021BF9B8 thumb ov203
 *   func_020310C4 0x020310C4 arm
 *   func_021BF924 0x021BF924 thumb ov203
 *   func_020307B0 0x020307B0 arm
 */
typedef struct { int kind;int values[9]; } Record;
extern Record *func_021BE9A4(int);
extern void func_021BF9B8(char *,int,Record *),func_020310C4(void *),func_021BF924(char *),func_020307B0(void *);
void func_021BF810(char *p)
{
    Record *r;
    int owner,i;
    owner=*(int *)(p+0x1C);r=func_021BE9A4(*(int *)(p+4));
    for(i=0;i<9999;i++,r++) {
        if(r->kind==18) break;
        func_021BF9B8(p,owner,r);
    }
    *(int *)(p+0xC)=1;
    func_020310C4(*(void **)(p+0x20));func_021BF924(p);func_020307B0(p);
}
