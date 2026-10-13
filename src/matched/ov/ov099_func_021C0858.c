/*
 * function: func_021C0858
 * address: 0x021C0858
 * packet: pkt_ov099_021C0858
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x0203CB00 and unlabelled ov099 0x021BDD98 lack outside witnesses.
 * blocker: 0x0203CB00 ARM verified MATCH, 52 bytes; copied from
 *   ov099_func_021BEB68.c (leaf-cb00-r1.log); no retry of the integrator's blocker.
 *   extern char *d_021469DC;
 *   extern void GFL_NET_STATE_FatalError(void);
 *   int GFL_NET_STATE_IsFatalError(void) {
 *       if (d_021469DC != 0) {
 *           if (*(void **)(d_021469DC + 8) == (void *)GFL_NET_STATE_FatalError) return 1;
 *       }
 *       return 0;
 *   }
 *   symbols: d_021469DC 0x021469DC data; GFL_NET_STATE_FatalError 0x0203CADC arm.
 *   Leaf's unresolved site is ARM9 0x0203CADC. No overlay leaf filed.
 * note (2026-10-04, lane17): lane17 wave D2: leaf func_021BDD98 (16 bytes, range test) filed EXACT as src/matched/ov/ov099_func_021BDD98.c. The 0x021BDD98 relocation still reports no witness because it has no shard yet; re-run after the integrator registers the leaf. Body and other 10 relocations are byte-correct.
 * note (2026-10-05, wD9r lane82): the enum-typed offset local (a stand-in) is removed. The real
 *   form is a pointer local `st = p + 0x24c;` set as the first statement and passed to
 *   func_021BDD48/func_021BDD54; the other uses are plain p + 0x274 and p + 0x1cc. mwcc keeps 0x24C
 *   in r5 and derives 0x274/0x1CC from it, as in the image. EXACT in c99 and c. Writing the other
 *   uses as st + 0x28 / st - 0x80 gives DIFF.
 *
 * symbols:
 *   GFL_NET_STATE_IsFatalError 0x0203CB00 arm
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
extern int GFL_NET_STATE_IsFatalError(void);
extern void func_021BE900(char *);
extern int func_021B97F4(char *);
extern void *func_021BE2A8(char *,int);
extern int func_021BA928(char *);
extern unsigned char func_021BDD48(char *,void *);
extern int func_021BDD54(char *,void *);
extern void func_021BAD74(char *);
extern int func_021BDD98(int);
typedef unsigned char  u8;
extern void func_021B9AE0(void *w, u8 *s);
int func_021C0858(char *p,int ret) {
    void *q; unsigned r; int v;
    char *st;
    st=p+0x24c;
    if(GFL_NET_STATE_IsFatalError()){func_021BE900(p);return ret;}
    q=func_021BE2A8(p,func_021B97F4(p+0x274));
    if(!func_021BA928(p))return ret;
    r=func_021BDD48(p,st);
    v=func_021BDD54(p,st);
    switch(r) {
    case 1: func_021BAD74(p); *(int *)(p+0x1cc)=64;break;
    case 2: case 5:
        if(func_021BDD98(v)){func_021BAD74(p);*(int *)(p+0x1cc)=36;break;}
    case 0: case 3: case 4: default:
        func_021B9AE0(p+0x274,q);
        *(int *)(p+0x1cc)=113;
        break;
    }
    return ret;
}
