/*
 * function: func_021DC2B0
 * address: 0x021DC2B0
 * packet: pkt_ov119_021DC2B0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B63D0 0x021B63D0 thumb ov067
 *   func_021B6448 0x021B6448 thumb ov067
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_021DD2F4 0x021DD2F4 thumb ov119
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021D8C6C 0x021D8C6C thumb ov119
 *   func_021DB198 0x021DB198 thumb ov119
 *   func_021DB45C 0x021DB45C thumb ov119
 *   func_021DF5D8 0x021DF5D8 thumb ov119
 *   func_021D9E54 0x021D9E54 thumb ov119
 *   func_021DBE70 0x021DBE70 thumb ov119
 */
extern void func_021B63D0(int);extern int func_021B6448(int);extern void func_021D8E84(void *,int);extern int func_021D8AA8(void *);extern int func_021DD2F4(void *);extern void func_021B6558(int,int,int);extern void func_021D8C6C(void *);extern void func_021DB198(void);extern void func_021DB45C(void);extern void func_021DF5D8(void);extern void func_021D9E54(void);extern void func_021DBE70(void);
void func_021DC2B0(char *p){func_021B63D0(*(int *)(p+0x9c0));switch(func_021B6448(*(int *)(p+0x9c0))) {case 1:func_021D8E84(p,(int)func_021DB198);return;case 7:func_021D8E84(p,(int)func_021DB45C);return;case 8:if(func_021D8AA8(p)){if(func_021DD2F4(p)){func_021B6558(*(int *)(p+0x9c0),7,0);func_021B6558(*(int *)(p+0x9c0),8,0);func_021D8C6C(p);func_021D8E84(p,(int)func_021DF5D8);return;}else{func_021B6558(*(int *)(p+0x9c0),7,1);func_021B6558(*(int *)(p+0x9c0),8,0);}}else{if(*(int *)(p+0xf84)==-1){func_021B6558(*(int *)(p+0x9c0),7,1);func_021B6558(*(int *)(p+0x9c0),8,0);}else{func_021D8E84(p,(int)func_021D9E54);return;}}func_021D8E84(p,(int)func_021DBE70);return;}}
