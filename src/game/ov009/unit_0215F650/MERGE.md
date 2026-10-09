# unit_0215F650 (ov009)

Two parts, both byte-exact. p01 (0215F650..0215FA90, SOC_GetHostByName .. SOC_Startup) is
one file: the three views of the soc.o statics block were unified into one SOCStatics struct.

Remaining boundary p01 | p02: a 12-byte linker veneer (`ldr ip,[pc]; bx ip; .word`) at
0x0215FA90..0x0215FA9C sits between SOC_Startup and SOC_InetNtoA. No function covers it, so
it stays a file boundary.

Overlapping externs kept in p01 because the original pool words are separate symbols:
g_021AA4BC_ip (0x021AA4BC), g_021AA4D4 (0x021AA4D4), g_021AA4DC (0x021AA4DC),
g_021AA50C (0x021AA50C). Folding them into SOCStatics changes the literal pool.

- `unit_0215F650_p01.c`
- `unit_0215F650_p02.c`
