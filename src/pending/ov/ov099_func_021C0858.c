/*
 * function: func_021C0858
 * address: 0x021C0858
 * packet: pkt_ov099_021C0858
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH
 * blocker: ARM9 0x0203CB00 and unlabelled ov099 0x021BDD98 lack outside witnesses.
 * blocker: 0x0203CB00 ARM verified MATCH, 52 bytes; copied from
 *   ov099_func_021BEB68.c (leaf-cb00-r1.log); no retry of Ilias's blocker.
 *   extern char *d_021469DC;
 *   extern void func_0203CADC(void);
 *   int func_0203CB00(void) {
 *       if (d_021469DC != 0) {
 *           if (*(void **)(d_021469DC + 8) == (void *)func_0203CADC) return 1;
 *       }
 *       return 0;
 *   }
 *   symbols: d_021469DC 0x021469DC data; func_0203CADC 0x0203CADC arm.
 *   Leaf's unresolved site is ARM9 0x0203CADC. No overlay leaf filed.
 * symbols:
 *   func_0203CB00 0x0203CB00 arm
 *   func_021BE900 0x021BE900 thumb ov099
 *   func_021B97F4 0x021B97F4 thumb ov099
 *   func_021BE2A8 0x021BE2A8 thumb ov099
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021BDD54 0x021BDD54 thumb ov099
 *   func_021BAD74 0x021BAD74 thumb ov099
 *   func_021BDD98 0x021BDD98 thumb ov099
 *   func_021B9AE0 0x021B9AE0 thumb ov099
 */
extern int func_0203CB00(void);
extern void func_021BE900(char *);
extern int func_021B97F4(char *);
extern void *func_021BE2A8(char *,int);
extern int func_021BA928(char *);
extern unsigned char func_021BDD48(char *,void *);
extern int func_021BDD54(char *,void *);
extern void func_021BAD74(char *);
extern int func_021BDD98(int);
extern void func_021B9AE0(char *,void *);
typedef enum { K24c=0x24c } Off;
int func_021C0858(char *p,int ret) {
    void *q; unsigned r; int v;
    Off o=K24c;
    if(func_0203CB00()){func_021BE900(p);return ret;}
    q=func_021BE2A8(p,func_021B97F4(p+(o+0x28)));
    if(!func_021BA928(p))return ret;
    r=func_021BDD48(p,p+o);
    v=func_021BDD54(p,p+o);
    switch(r) {
    case 1: func_021BAD74(p); *(int *)(p+(o-0x80))=64;break;
    case 2: case 5:
        if(func_021BDD98(v)){func_021BAD74(p);*(int *)(p+(o-0x80))=36;break;}
    case 0: case 3: case 4: default:
        func_021B9AE0(p+0x274,q);
        *(int *)(p+0x1cc)=113;
        break;
    }
    return ret;
}
