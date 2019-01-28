EESchema Schematic File Version 4
LIBS:Tooling Board-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 7
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L EER:LN298P U402
U 1 1 5C4E06F8
P 5730 3140
F 0 "U402" H 5730 4305 50  0000 C CNN
F 1 "LN298P" H 5730 4214 50  0000 C CNN
F 2 "EER:POWER-SO20" H 5730 2940 50  0001 C CNN
F 3 "https://www.digikey.ca/product-detail/en/stmicroelectronics/L298P/497-1396-5-ND/585919" H 5730 2940 50  0001 C CNN
	1    5730 3140
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x01 J403
U 1 1 5C4E06FA
P 8200 2840
F 0 "J403" H 8279 2882 50  0000 L CNN
F 1 "Screw Terminal" H 8279 2791 50  0000 L CNN
F 2 "EER:RingTerminal" H 8200 2840 50  0001 C CNN
F 3 "~" H 8200 2840 50  0001 C CNN
	1    8200 2840
	1    0    0    -1  
$EndComp
Wire Wire Line
	6330 2840 8000 2840
$Comp
L Connector:Screw_Terminal_01x01 J404
U 1 1 5C4E06FD
P 8200 3040
F 0 "J404" H 8279 3082 50  0000 L CNN
F 1 "Screw Terminal" H 8279 2991 50  0000 L CNN
F 2 "EER:RingTerminal" H 8200 3040 50  0001 C CNN
F 3 "~" H 8200 3040 50  0001 C CNN
	1    8200 3040
	1    0    0    -1  
$EndComp
Wire Wire Line
	6330 3040 8000 3040
$Comp
L Connector:Screw_Terminal_01x01 J402
U 1 1 5C4E06FF
P 3260 3040
F 0 "J402" H 3339 3082 50  0000 L CNN
F 1 "Screw Terminal" H 3339 2991 50  0000 L CNN
F 2 "EER:RingTerminal" H 3260 3040 50  0001 C CNN
F 3 "~" H 3260 3040 50  0001 C CNN
	1    3260 3040
	-1   0    0    1   
$EndComp
$Comp
L Connector:Screw_Terminal_01x01 J401
U 1 1 5C4E0701
P 3260 2840
F 0 "J401" H 3339 2882 50  0000 L CNN
F 1 "Screw Terminal" H 3339 2791 50  0000 L CNN
F 2 "EER:RingTerminal" H 3260 2840 50  0001 C CNN
F 3 "~" H 3260 2840 50  0001 C CNN
	1    3260 2840
	-1   0    0    1   
$EndComp
Wire Wire Line
	5130 2840 3460 2840
Wire Wire Line
	6330 2240 6980 2240
Wire Wire Line
	6980 2240 6980 2440
Wire Wire Line
	5130 4040 4660 4040
Wire Wire Line
	4660 4040 4660 4370
Wire Wire Line
	6950 4040 6950 4300
Wire Wire Line
	5130 2240 4500 2240
Wire Wire Line
	4500 2240 4500 2440
$Comp
L power:GND #PWR0134
U 1 1 5C4C7BF9
P 6980 2590
F 0 "#PWR0134" H 6980 2340 50  0001 C CNN
F 1 "GND" H 6985 2417 50  0000 C CNN
F 2 "" H 6980 2590 50  0001 C CNN
F 3 "" H 6980 2590 50  0001 C CNN
	1    6980 2590
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0135
U 1 1 5C4C7C15
P 4500 2600
F 0 "#PWR0135" H 4500 2350 50  0001 C CNN
F 1 "GND" H 4505 2427 50  0000 C CNN
F 2 "" H 4500 2600 50  0001 C CNN
F 3 "" H 4500 2600 50  0001 C CNN
	1    4500 2600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0136
U 1 1 5C4E0706
P 4660 4370
F 0 "#PWR0136" H 4660 4120 50  0001 C CNN
F 1 "GND" H 4665 4197 50  0000 C CNN
F 2 "" H 4660 4370 50  0001 C CNN
F 3 "" H 4660 4370 50  0001 C CNN
	1    4660 4370
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0137
U 1 1 5C4C7C7B
P 6950 4300
F 0 "#PWR0137" H 6950 4050 50  0001 C CNN
F 1 "GND" H 6955 4127 50  0000 C CNN
F 2 "" H 6950 4300 50  0001 C CNN
F 3 "" H 6950 4300 50  0001 C CNN
	1    6950 4300
	1    0    0    -1  
$EndComp
NoConn ~ 6330 2640
NoConn ~ 5130 2640
Wire Wire Line
	5130 3640 4710 3640
Wire Wire Line
	6330 3440 6750 3440
Text GLabel 4710 3640 0    50   Input ~ 0
EnableA1
Text GLabel 6750 3440 2    50   Input ~ 0
EnableB1
$Comp
L Device:C C401
U 1 1 5C4E070A
P 3980 3490
F 0 "C401" H 4095 3536 50  0000 L CNN
F 1 "100nF" H 4095 3445 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 4018 3340 50  0001 C CNN
F 3 "~" H 3980 3490 50  0001 C CNN
	1    3980 3490
	1    0    0    -1  
$EndComp
Wire Wire Line
	5130 3240 4210 3240
Wire Wire Line
	3980 3240 3980 3340
$Comp
L power:GND #PWR0138
U 1 1 5C4E070D
P 3980 3790
F 0 "#PWR0138" H 3980 3540 50  0001 C CNN
F 1 "GND" H 3985 3617 50  0000 C CNN
F 2 "" H 3980 3790 50  0001 C CNN
F 3 "" H 3980 3790 50  0001 C CNN
	1    3980 3790
	1    0    0    -1  
$EndComp
Wire Wire Line
	3980 3640 3980 3790
Wire Wire Line
	6330 4040 6950 4040
Wire Wire Line
	6330 3840 7320 3840
Wire Wire Line
	7320 3840 7320 4000
Wire Wire Line
	7320 3840 7320 3760
Connection ~ 7320 3840
Wire Wire Line
	4210 3190 4210 3240
Connection ~ 4210 3240
Wire Wire Line
	4210 3240 3980 3240
$Comp
L Device:C C402
U 1 1 5C4C9D1A
P 7320 4150
F 0 "C402" H 7435 4196 50  0000 L CNN
F 1 "100nF" H 7435 4105 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 7358 4000 50  0001 C CNN
F 3 "~" H 7320 4150 50  0001 C CNN
	1    7320 4150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0139
U 1 1 5C4C9D20
P 7320 4450
F 0 "#PWR0139" H 7320 4200 50  0001 C CNN
F 1 "GND" H 7325 4277 50  0000 C CNN
F 2 "" H 7320 4450 50  0001 C CNN
F 3 "" H 7320 4450 50  0001 C CNN
	1    7320 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7320 4300 7320 4450
$Comp
L power:+5V #PWR0140
U 1 1 5C4C9F8F
P 7320 3760
F 0 "#PWR0140" H 7320 3610 50  0001 C CNN
F 1 "+5V" H 7335 3933 50  0000 C CNN
F 2 "" H 7320 3760 50  0001 C CNN
F 3 "" H 7320 3760 50  0001 C CNN
	1    7320 3760
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0141
U 1 1 5C4E0715
P 4210 3190
F 0 "#PWR0141" H 4210 3040 50  0001 C CNN
F 1 "+12V" H 4370 3270 50  0000 C CNN
F 2 "" H 4210 3190 50  0001 C CNN
F 3 "" H 4210 3190 50  0001 C CNN
	1    4210 3190
	1    0    0    -1  
$EndComp
Wire Wire Line
	3460 3040 5130 3040
$Comp
L Device:R_US R402
U 1 1 5C4CABF0
P 6650 2440
F 0 "R402" V 6540 2610 50  0000 C CNN
F 1 "0.5" V 6540 2280 50  0000 C CNN
F 2 "Resistors_SMD:R_1206" V 6690 2430 50  0001 C CNN
F 3 "~" H 6650 2440 50  0001 C CNN
	1    6650 2440
	0    1    1    0   
$EndComp
$Comp
L Device:R_US R401
U 1 1 5C4E0719
P 4810 2440
F 0 "R401" V 4700 2610 50  0000 C CNN
F 1 "0.5" V 4700 2280 50  0000 C CNN
F 2 "Resistors_SMD:R_1206" V 4850 2430 50  0001 C CNN
F 3 "~" H 4810 2440 50  0001 C CNN
	1    4810 2440
	0    1    1    0   
$EndComp
Wire Wire Line
	4960 2440 5130 2440
Wire Wire Line
	4660 2440 4500 2440
Connection ~ 4500 2440
Wire Wire Line
	4500 2440 4500 2600
Wire Wire Line
	6500 2440 6330 2440
Wire Wire Line
	6800 2440 6980 2440
Connection ~ 6980 2440
Wire Wire Line
	6980 2440 6980 2590
Text Label 4790 3440 0    50   ~ 0
Input1
Wire Wire Line
	4770 3440 5130 3440
Text Label 4790 3840 0    50   ~ 0
Input2
Wire Wire Line
	4760 3840 5130 3840
Text Label 6440 3240 0    50   ~ 0
Input4
Wire Wire Line
	6330 3240 6690 3240
Text Label 6440 3640 0    50   ~ 0
Input3
Wire Wire Line
	6330 3640 6680 3640
$Comp
L EER:74LVC2G14 U401
U 1 1 5C4CF224
P 2460 5130
F 0 "U401" H 2460 5645 50  0000 C CNN
F 1 "74LVC2G14" H 2460 5554 50  0000 C CNN
F 2 "EER:PSON50P140X100X40-6N" H 2460 5130 50  0001 C CNN
F 3 "https://www.digikey.ca/product-detail/en/diodes-incorporated/74LVC2G14FZ4-7/74LVC2G14FZ4-7DICT-ND/2901046" H 2460 5130 50  0001 C CNN
	1    2460 5130
	1    0    0    -1  
$EndComp
Wire Wire Line
	2060 4880 1790 4880
Wire Wire Line
	1790 4880 1790 4620
Wire Wire Line
	1790 4620 1430 4620
Wire Wire Line
	1790 4620 2100 4620
Connection ~ 1790 4620
Wire Wire Line
	2860 4880 3170 4880
Wire Wire Line
	2860 5130 3040 5130
Wire Wire Line
	3040 5130 3040 5050
Wire Wire Line
	2860 5380 3150 5380
Wire Wire Line
	2060 5130 1940 5130
Wire Wire Line
	1940 5130 1940 5710
$Comp
L power:GND #PWR0142
U 1 1 5C4D22A3
P 1940 5710
F 0 "#PWR0142" H 1940 5460 50  0001 C CNN
F 1 "GND" H 1945 5537 50  0000 C CNN
F 2 "" H 1940 5710 50  0001 C CNN
F 3 "" H 1940 5710 50  0001 C CNN
	1    1940 5710
	1    0    0    -1  
$EndComp
Wire Wire Line
	2060 5380 2010 5380
Wire Wire Line
	2010 5380 2010 5580
Wire Wire Line
	2010 5580 2310 5580
Wire Wire Line
	2010 5380 1660 5380
Connection ~ 2010 5380
$Comp
L power:+5V #PWR0143
U 1 1 5C4E071E
P 3040 5050
F 0 "#PWR0143" H 3040 4900 50  0001 C CNN
F 1 "+5V" H 3150 5120 50  0000 C CNN
F 2 "" H 3040 5050 50  0001 C CNN
F 3 "" H 3040 5050 50  0001 C CNN
	1    3040 5050
	1    0    0    -1  
$EndComp
Text Label 1850 4620 0    50   ~ 0
Input1
Text Label 2920 4880 0    50   ~ 0
Input2
Text GLabel 1430 4620 0    50   Input ~ 0
DirA1
Text GLabel 1660 5380 0    50   Input ~ 0
DirB1
Text Label 2920 5380 0    50   ~ 0
Input4
Text Label 2050 5580 0    50   ~ 0
Input3
Text Notes 2210 4440 0    50   ~ 0
Logic Inverter
Text Notes 5480 1790 0    50   ~ 0
Dual H-Bridge
Text Notes 2860 2620 0    50   ~ 10
Motor A1
Text Notes 8160 2690 0    50   ~ 10
Motor B1
Text Notes 7830 6980 0    197  Italic 39
DC Motor Driver
$EndSCHEMATC
