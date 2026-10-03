/*
 * function: func_021B6C2C
 * address: 0x021B6C2C
 * packet: pkt_ov174_021B6C2C
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B61C4 0x021B61C4 thumb ov174
 *   func_02012704 0x02012704 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
struct S020315D4;extern void func_021B61C4(unsigned char *),func_02012704(unsigned char *),func_020307B0(void *),func_020315D4(struct S020315D4 *),func_020306F0(void *);
int func_021B6C2C(struct S020315D4 *a,unsigned unused,int own,unsigned char *p) {func_021B61C4(p);if(own==0){func_02012704(*(unsigned char **)(*(char **)(p+48)+4));func_020307B0(*(void **)(p+48));}func_020315D4(a);func_020306F0((void *)85);return 1;}
