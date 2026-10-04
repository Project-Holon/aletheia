/*
 * function: func_021BFED0
 * address: 0x021BFED0
 * packet: pkt_ov099_021BFED0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 func_0203CB00 at +0006; concrete bytes match, no ARM9 source written.
 * blocker: scratch one --arm (no region), dsi/1.1p1 -O4,p: MATCH 52 bytes;
 *   g_021469DC 0x021469DC data resolves, func_0203CADC 0x0203CADC arm remains unresolved.
 *   typedef struct { int pad[2]; void (*callback)(void); } Object;
 *   extern Object *g_021469DC;
 *   extern void func_0203CADC(void);
 *   int func_0203CB00(void) {
 *       if(g_021469DC && g_021469DC->callback==func_0203CADC)return 1;
 *       return 0;
 *   }
 * blocker: nested scratch one --arm, same compiler/flags: func_0203CADC EXACT 36 bytes;
 *   file_020A7BA8 0x020A7BA8 data; message_020A7C7C 0x020A7C7C data;
 *   func_02034714 0x02034714 arm.
 *   extern const char file_020A7BA8[];
 *   extern const char message_020A7C7C[];
 *   extern void func_02034714(const char *,unsigned,const char *);
 *   void func_0203CADC(void) {
 *       func_02034714(file_020A7BA8,0x8d8,message_020A7C7C);
 *   }
 * diagnosis: caller-only tu --suggest-split MATCH 204 bytes; no viable split.
 * symbols:
 *   func_0203CB00 0x0203CB00 arm
 *   func_021BE900 0x021BE900 thumb ov099
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_020362DC 0x020362DC arm
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_0203C554 0x0203C554 arm
 *   func_021BDD0C 0x021BDD0C thumb ov099
 *   func_021B96CC 0x021B96CC thumb ov099
 *   func_021C19A8 0x021C19A8 thumb ov099
 *   func_021BAEDC 0x021BAEDC thumb ov099
 *   func_021B97F4 0x021B97F4 thumb ov099
 *   func_021BE2A8 0x021BE2A8 thumb ov099
 *   func_021B9AE0 0x021B9AE0 thumb ov099
 *   func_021C2408 0x021C2408 thumb ov099
 */
extern int func_0203CB00(void);
extern void func_021BE900(char *);
extern unsigned func_021BDD48(char *,void *);
extern void func_021C18C8(char *,int,int);
extern int func_021BA928(char *);
extern int func_020362DC(void);
extern void func_021BA8EC(char *);
extern void func_0203C554(int);
extern void func_021BDD0C(char *,int);
extern int func_021B96CC(char *);
extern void func_021C19A8(char *);
extern void func_021BAEDC(char *);
extern int func_021B97F4(char *);
extern void *func_021BE2A8(char *,int);
extern void func_021B9AE0(char *,void *);
extern void func_021C2408(char *);
int func_021BFED0(char *p,int ret)
{
    if(func_0203CB00()){func_021BE900(p);return ret;}
    if(func_021BDD48(p,*(void **)(p+8))!=1)func_021C18C8(p,1,2);
    if(!func_021BA928(p)){*(int *)(p+0x1e0)=30;return ret;}
    --*(int *)(p+0x1e0);
    if((func_020362DC()&3)||!*(int *)(p+0x1e0)){
        func_021BA8EC(p);
        func_0203C554(1);
        func_021BDD0C(p,0);
        if(!func_021B96CC(p+0x274)){
            *(int *)(p+0x1e0)=20;
            *(int *)(p+0x1cc)=57;
        }else{
            func_021C19A8(p);
            func_021BAEDC(p);
            *(int *)(p+0x1f0)=-1;
            *(int *)(p+0x1cc)=11;
            func_021B9AE0(p+0x274,func_021BE2A8(p,func_021B97F4(p+0x274)));
            func_021C2408(p);
        }
    }
    return ret;
}
