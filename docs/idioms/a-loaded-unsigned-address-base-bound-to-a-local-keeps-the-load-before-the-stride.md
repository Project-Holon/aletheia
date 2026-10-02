# A loaded unsigned address base bound to a local keeps the load before the stride

summary: In Thumb raw-address indexing, binding a loaded u32 base to a local before adding a scaled index restores the base load into r1 before the stride constant in r0. An inline base load swaps those registers and schedules the stride first.

Found in: src/matched/ov/ov010_func_0216E51C.c (0x0216E51C), src/matched/ov/ov010_func_0216E544.c (0x0216E544).

With dsi/1.1p1, -O4,p, Thumb c99, this form gives five concrete bytes wrong in each function:

```c
p = (Vec *)(*(unsigned int *)((char *)func_0216D67C(a) + 44) + i * 12);
```

It emits `movs r1,#12; ldr r0,[r0,#44]; muls r1,index,r1`.
Reversing the addition operands and making the index unsigned do not change that residue.
Binding the loaded base closes these two at EXACT/EXACT*:

```c
unsigned int base;
base = *(unsigned int *)((char *)func_0216D67C(a) + 44);
p = (Vec *)(base + i * 12);
```

This emits `ldr r1,[r0,#44]; movs r0,#12; muls r0,index,r0`.
The address addition is unsigned, avoiding signed address overflow and an assumption that the indexed pointer is within a declared Vec array.
For these callers, primary body evidence also bounds the signed multiplication: 0216E4EC returns 30 on its failed test at 0216E4FA, otherwise returns 0216E4B0's result; E4B0 returns a halfword read at 0216E4CA or 30. Thus i is 0..65535 and i*12 is at most 786420.
In the related E57C caller, which computes the address before calling the position initializer, the same named-base form instead sinks the address arithmetic after that call and gives a 23-byte DIFF. This finding is specific to the two consumers above.
