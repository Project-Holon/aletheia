/*
 * unit: yes
 * function: func_021F10D4,func_021F10DC,func_021F10E4,func_021F10EC,func_021F10F4,func_021F10FC,func_021F1104,func_021F110C
 * address: 0x021F10D4
 * packet: pkt_ov107_021F10D4
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * leaf: parent cleared all eight original Thumb starts; 60 bytes stop
 * before existing 021F1110. Both 10DC and10E4 read bit4 in the ROM.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {
    u16 b00:1,b01:1,b02:1,b03:1,b04:1,b05:1,b06:1,b07:1;
    u16 b08:1,b09:1,b10:1,b11:1,b12:1,b13:1,b14:1,b15:1;
} Flags;
typedef struct { u8 pad00[0x18]; Flags f18; u16 f1a; u8 f1c; } State;
int func_021F10D4(State *p) { return p->f18.b03; }
int func_021F10DC(State *p) { return p->f18.b04; }
int func_021F10E4(State *p) { return p->f18.b04; }
int func_021F10EC(State *p) { return p->f18.b06; }
int func_021F10F4(State *p) { return p->f18.b07; }
int func_021F10FC(State *p) { return p->f18.b08; }
int func_021F1104(State *p) { return p->f18.b10; }
int func_021F110C(State *p) { return p->f1c; }
