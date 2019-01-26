EESchema Schematic File Version 4
LIBS:Tooling Board-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 8 7
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
L power:GND #PWR0174
U 1 1 5BDA3309
P 1750 2600
F 0 "#PWR0174" H 1750 2350 50  0001 C CNN
F 1 "GND" H 1755 2427 50  0000 C CNN
F 2 "" H 1750 2600 50  0001 C CNN
F 3 "" H 1750 2600 50  0001 C CNN
	1    1750 2600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R801
U 1 1 5BDA3446
P 2160 2400
F 0 "R801" V 1953 2400 50  0000 C CNN
F 1 "4.7M" V 2044 2400 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 2090 2400 50  0001 C CNN
F 3 "~" H 2160 2400 50  0001 C CNN
	1    2160 2400
	0    1    1    0   
$EndComp
Wire Wire Line
	2310 2400 2500 2400
Wire Wire Line
	2500 2400 2500 2550
$Comp
L Device:C C802
U 1 1 5BDA36F4
P 2500 2700
F 0 "C802" H 2615 2746 50  0000 L CNN
F 1 "2.2nF" H 2615 2655 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2538 2550 50  0001 C CNN
F 3 "~" H 2500 2700 50  0001 C CNN
	1    2500 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2500 2850 2500 2950
$Comp
L power:GND #PWR0175
U 1 1 5BDA3777
P 2500 2950
F 0 "#PWR0175" H 2500 2700 50  0001 C CNN
F 1 "GND" H 2505 2777 50  0000 C CNN
F 2 "" H 2500 2950 50  0001 C CNN
F 3 "" H 2500 2950 50  0001 C CNN
	1    2500 2950
	1    0    0    -1  
$EndComp
Connection ~ 2500 2400
$Comp
L Device:C C801
U 1 1 5BDA4419
P 2300 3500
F 0 "C801" H 2415 3546 50  0000 L CNN
F 1 "10uF" H 2415 3455 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2338 3350 50  0001 C CNN
F 3 "~" H 2300 3500 50  0001 C CNN
	1    2300 3500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C803
U 1 1 5BDA444B
P 2850 3500
F 0 "C803" H 2965 3546 50  0000 L CNN
F 1 "100nF" H 2965 3455 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2888 3350 50  0001 C CNN
F 3 "~" H 2850 3500 50  0001 C CNN
	1    2850 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 3350 2850 3350
Wire Wire Line
	2300 3650 2300 3800
Wire Wire Line
	2300 3800 2850 3800
Wire Wire Line
	2850 3800 2850 3650
$Comp
L power:GND #PWR0176
U 1 1 5BDA44FA
P 2300 3800
F 0 "#PWR0176" H 2300 3550 50  0001 C CNN
F 1 "GND" H 2305 3627 50  0000 C CNN
F 2 "" H 2300 3800 50  0001 C CNN
F 3 "" H 2300 3800 50  0001 C CNN
	1    2300 3800
	1    0    0    -1  
$EndComp
Connection ~ 2300 3800
$Comp
L power:-5V #PWR0177
U 1 1 5BDA467B
P 2850 3350
F 0 "#PWR0177" H 2850 3450 50  0001 C CNN
F 1 "-5V" H 2865 3523 50  0000 C CNN
F 2 "" H 2850 3350 50  0001 C CNN
F 3 "" H 2850 3350 50  0001 C CNN
	1    2850 3350
	1    0    0    -1  
$EndComp
Connection ~ 2850 3350
Wire Wire Line
	2500 2400 3350 2400
$Comp
L Device:C C806
U 1 1 5BDA50C0
P 3850 3550
F 0 "C806" V 3598 3550 50  0000 C CNN
F 1 "1uF" V 3689 3550 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 3888 3400 50  0001 C CNN
F 3 "~" H 3850 3550 50  0001 C CNN
	1    3850 3550
	0    1    1    0   
$EndComp
Wire Wire Line
	4000 3550 4500 3550
$Comp
L Device:R R803
U 1 1 5BDA531A
P 4500 3870
F 0 "R803" H 4570 3916 50  0000 L CNN
F 1 "2.2k" H 4570 3825 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4430 3870 50  0001 C CNN
F 3 "~" H 4500 3870 50  0001 C CNN
	1    4500 3870
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 4300 4500 4020
Wire Wire Line
	4500 4600 4500 4850
Wire Wire Line
	4500 4850 4300 4850
$Comp
L Device:R R802
U 1 1 5BDA6862
P 4150 4850
F 0 "R802" V 3943 4850 50  0000 C CNN
F 1 "1k" V 4034 4850 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4080 4850 50  0001 C CNN
F 3 "~" H 4150 4850 50  0001 C CNN
	1    4150 4850
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0178
U 1 1 5BDA68EF
P 3800 4850
F 0 "#PWR0178" H 3800 4600 50  0001 C CNN
F 1 "GND" V 3805 4722 50  0000 R CNN
F 2 "" H 3800 4850 50  0001 C CNN
F 3 "" H 3800 4850 50  0001 C CNN
	1    3800 4850
	0    1    1    0   
$EndComp
Wire Wire Line
	4000 4850 3800 4850
Wire Wire Line
	3250 2600 3350 2600
Wire Wire Line
	2850 3350 3550 3350
Wire Wire Line
	3550 3350 3550 2800
$Comp
L Device:C C805
U 1 1 5BDA8A64
P 3550 1800
F 0 "C805" H 3665 1846 50  0000 L CNN
F 1 "10uF" H 3665 1755 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 3588 1650 50  0001 C CNN
F 3 "~" H 3550 1800 50  0001 C CNN
	1    3550 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 3550 3700 3550
Wire Wire Line
	4500 3720 4500 3550
Wire Wire Line
	4500 2500 3950 2500
Connection ~ 3250 3550
Connection ~ 4500 3550
Wire Wire Line
	4500 3550 4500 2500
Wire Wire Line
	3000 1650 3550 1650
Wire Wire Line
	3550 1650 3550 1550
Connection ~ 3550 1650
$Comp
L power:GND #PWR0179
U 1 1 5BDDE67A
P 3550 1550
F 0 "#PWR0179" H 3550 1300 50  0001 C CNN
F 1 "GND" H 3555 1377 50  0000 C CNN
F 2 "" H 3550 1550 50  0001 C CNN
F 3 "" H 3550 1550 50  0001 C CNN
	1    3550 1550
	-1   0    0    1   
$EndComp
Wire Wire Line
	4500 2500 5700 2500
Connection ~ 4500 2500
$Comp
L Device:R R804
U 1 1 5BDDFE56
P 5850 2500
F 0 "R804" V 5643 2500 50  0000 C CNN
F 1 "30k" V 5734 2500 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5780 2500 50  0001 C CNN
F 3 "~" H 5850 2500 50  0001 C CNN
	1    5850 2500
	0    1    1    0   
$EndComp
Wire Wire Line
	6000 2500 6350 2500
Wire Wire Line
	6350 2500 6350 1450
Wire Wire Line
	5500 1550 5500 1570
$Comp
L Device:C C807
U 1 1 5BDE2305
P 5500 1720
F 0 "C807" H 5615 1766 50  0000 L CNN
F 1 "10uF" H 5615 1675 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 5538 1570 50  0001 C CNN
F 3 "~" H 5500 1720 50  0001 C CNN
	1    5500 1720
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0180
U 1 1 5BDE3091
P 5500 2010
F 0 "#PWR0180" H 5500 1760 50  0001 C CNN
F 1 "GND" H 5505 1837 50  0000 C CNN
F 2 "" H 5500 2010 50  0001 C CNN
F 3 "" H 5500 2010 50  0001 C CNN
	1    5500 2010
	1    0    0    -1  
$EndComp
$Comp
L Device:C C809
U 1 1 5BDE526F
P 5980 1750
F 0 "C809" H 6095 1796 50  0000 L CNN
F 1 "100nF" H 6095 1705 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 6018 1600 50  0001 C CNN
F 3 "~" H 5980 1750 50  0001 C CNN
	1    5980 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5980 1550 5980 1600
Wire Wire Line
	6350 1450 7150 1450
$Comp
L Device:R R806
U 1 1 5BDEA1B1
P 7300 1450
F 0 "R806" V 7093 1450 50  0000 C CNN
F 1 "30k" V 7184 1450 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 7230 1450 50  0001 C CNN
F 3 "~" H 7300 1450 50  0001 C CNN
	1    7300 1450
	0    1    1    0   
$EndComp
Wire Wire Line
	6350 2500 6350 2760
Connection ~ 6350 2500
$Comp
L Device:R R805
U 1 1 5BDEB94E
P 6350 2910
F 0 "R805" H 6420 2956 50  0000 L CNN
F 1 "75k" H 6420 2865 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6280 2910 50  0001 C CNN
F 3 "~" H 6350 2910 50  0001 C CNN
	1    6350 2910
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 3060 6350 3400
Wire Wire Line
	6350 3400 6400 3400
$Comp
L power:-5V #PWR0181
U 1 1 5BDECC40
P 6400 3400
F 0 "#PWR0181" H 6400 3500 50  0001 C CNN
F 1 "-5V" V 6415 3528 50  0000 L CNN
F 2 "" H 6400 3400 50  0001 C CNN
F 3 "" H 6400 3400 50  0001 C CNN
	1    6400 3400
	0    1    1    0   
$EndComp
Wire Wire Line
	6550 2300 6550 2200
$Comp
L power:GND #PWR0182
U 1 1 5BDF333C
P 6550 2200
F 0 "#PWR0182" H 6550 1950 50  0001 C CNN
F 1 "GND" H 6555 2027 50  0000 C CNN
F 2 "" H 6550 2200 50  0001 C CNN
F 3 "" H 6550 2200 50  0001 C CNN
	1    6550 2200
	-1   0    0    1   
$EndComp
Wire Wire Line
	6950 3050 6870 3050
Wire Wire Line
	6950 3050 6950 3100
Connection ~ 6950 3050
Wire Wire Line
	6950 3050 7460 3050
Wire Wire Line
	7460 3050 7460 3100
$Comp
L Device:C C810
U 1 1 5BDF791D
P 6950 3250
F 0 "C810" H 7065 3296 50  0000 L CNN
F 1 "10uF" H 7065 3205 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 6988 3100 50  0001 C CNN
F 3 "~" H 6950 3250 50  0001 C CNN
	1    6950 3250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C813
U 1 1 5BDF8522
P 7460 3250
F 0 "C813" H 7575 3296 50  0000 L CNN
F 1 "100nF" H 7575 3205 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 7498 3100 50  0001 C CNN
F 3 "~" H 7460 3250 50  0001 C CNN
	1    7460 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6950 2700 6950 3050
Wire Wire Line
	7460 3400 6950 3400
$Comp
L power:GND #PWR0183
U 1 1 5BE00128
P 6950 3400
F 0 "#PWR0183" H 6950 3150 50  0001 C CNN
F 1 "GND" H 6955 3227 50  0000 C CNN
F 2 "" H 6950 3400 50  0001 C CNN
F 3 "" H 6950 3400 50  0001 C CNN
	1    6950 3400
	1    0    0    -1  
$EndComp
Connection ~ 6950 3400
$Comp
L power:-5V #PWR0184
U 1 1 5BE007DB
P 6870 3050
F 0 "#PWR0184" H 6870 3150 50  0001 C CNN
F 1 "-5V" V 6885 3178 50  0000 L CNN
F 2 "" H 6870 3050 50  0001 C CNN
F 3 "" H 6870 3050 50  0001 C CNN
	1    6870 3050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5500 1550 5980 1550
Wire Wire Line
	6750 2300 6550 2300
Wire Wire Line
	6750 2500 6350 2500
Wire Wire Line
	5980 1550 6950 1550
Wire Wire Line
	6950 1550 6950 2100
Connection ~ 5980 1550
Wire Wire Line
	7450 1450 7900 1450
Wire Wire Line
	7900 1450 7900 2400
Connection ~ 7900 2400
Text Notes 5540 4400 0    50   ~ 0
Converts the +5 to -5 volts
$Comp
L power:+5V #PWR0185
U 1 1 5BE2F1EF
P 8510 3940
F 0 "#PWR0185" H 8510 3790 50  0001 C CNN
F 1 "+5V" H 8525 4068 50  0000 L CNN
F 2 "" H 8510 3940 50  0001 C CNN
F 3 "" H 8510 3940 50  0001 C CNN
	1    8510 3940
	1    0    0    -1  
$EndComp
Wire Wire Line
	8510 3940 8510 4040
$Comp
L Device:R R809
U 1 1 5BE3019B
P 8510 4190
F 0 "R809" H 8390 4280 50  0000 C CNN
F 1 "1k" H 8400 4140 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 8440 4190 50  0001 C CNN
F 3 "~" H 8510 4190 50  0001 C CNN
	1    8510 4190
	-1   0    0    1   
$EndComp
Wire Wire Line
	8510 4340 8510 4490
$Comp
L Device:LED D801
U 1 1 5BE3119A
P 8510 4640
F 0 "D801" V 8502 4385 50  0000 C CNN
F 1 "GREEN" V 8590 4450 50  0000 C CNN
F 2 "LEDs:LED_0805_HandSoldering" H 8510 4640 50  0001 C CNN
F 3 "~" H 8510 4640 50  0001 C CNN
	1    8510 4640
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8510 4790 8510 5040
$Comp
L power:GND #PWR0186
U 1 1 5BE3223A
P 8510 5040
F 0 "#PWR0186" H 8510 4790 50  0001 C CNN
F 1 "GND" H 8580 4900 50  0000 R CNN
F 2 "" H 8510 5040 50  0001 C CNN
F 3 "" H 8510 5040 50  0001 C CNN
	1    8510 5040
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 2600 3250 3550
Wire Wire Line
	5500 1870 5500 1940
Wire Wire Line
	5500 1940 5980 1940
Wire Wire Line
	5980 1940 5980 1900
Connection ~ 5500 1940
Wire Wire Line
	5500 1940 5500 2010
$Comp
L Connector_Generic:Conn_01x02 J801
U 1 1 5C5052C6
P 1510 2500
F 0 "J801" H 1430 2175 50  0000 C CNN
F 1 "Conn_01x02" H 1430 2266 50  0000 C CNN
F 2 "Junction Box:70553-02" H 1510 2500 50  0001 C CNN
F 3 "~" H 1510 2500 50  0001 C CNN
	1    1510 2500
	-1   0    0    1   
$EndComp
Wire Wire Line
	1710 2500 1750 2500
Wire Wire Line
	1750 2500 1750 2600
Wire Wire Line
	1710 2400 2010 2400
$Comp
L Device:C C804
U 1 1 5BDDD77F
P 3000 1800
F 0 "C804" H 3115 1846 50  0000 L CNN
F 1 "100nF" H 3115 1755 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 3038 1650 50  0001 C CNN
F 3 "~" H 3000 1800 50  0001 C CNN
	1    3000 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 1950 3550 2010
Wire Wire Line
	3550 2010 3000 2010
Wire Wire Line
	3000 2010 3000 1950
Wire Wire Line
	3550 2010 3550 2200
Connection ~ 3550 2010
Connection ~ 3000 2010
$Comp
L power:+5V #PWR0187
U 1 1 5C511096
P 2730 1950
F 0 "#PWR0187" H 2730 1800 50  0001 C CNN
F 1 "+5V" H 2745 2123 50  0000 C CNN
F 2 "" H 2730 1950 50  0001 C CNN
F 3 "" H 2730 1950 50  0001 C CNN
	1    2730 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2730 1950 2730 2010
Wire Wire Line
	2730 2010 3000 2010
Text Notes 8340 6940 0    197  Italic 39
pH Sensor
Text Notes 860  2470 0    50   ~ 0
To pH Sensor
$Comp
L Device:R_POT_US RV801
U 1 1 5C516D7D
P 4500 4450
F 0 "RV801" H 4433 4404 50  0000 R CNN
F 1 "5k" H 4433 4495 50  0000 R CNN
F 2 "Potentiometers:Potentiometer_Trimmer_Bourns_3269W" H 4500 4450 50  0001 C CNN
F 3 "https://www.digikey.ca/product-detail/en/bourns-inc/3296W-1-502LF/3296W-502LF-ND/1088058" H 4500 4450 50  0001 C CNN
	1    4500 4450
	-1   0    0    1   
$EndComp
Wire Wire Line
	4350 4450 3250 4450
Wire Wire Line
	3250 3550 3250 4450
$Comp
L power:+5V #PWR0188
U 1 1 5C51A056
P 5980 1490
F 0 "#PWR0188" H 5980 1340 50  0001 C CNN
F 1 "+5V" H 5995 1618 50  0000 L CNN
F 2 "" H 5980 1490 50  0001 C CNN
F 3 "" H 5980 1490 50  0001 C CNN
	1    5980 1490
	1    0    0    -1  
$EndComp
Wire Wire Line
	5980 1490 5980 1550
Text GLabel 9220 2790 2    50   Input ~ 0
V_PH
$Comp
L Device:R R808
U 1 1 5C52E8F2
P 8450 2960
F 0 "R808" H 8520 3006 50  0000 L CNN
F 1 "33k" H 8520 2915 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 8380 2960 50  0001 C CNN
F 3 "~" H 8450 2960 50  0001 C CNN
	1    8450 2960
	1    0    0    -1  
$EndComp
$Comp
L Device:R R807
U 1 1 5C52E956
P 8450 2630
F 0 "R807" H 8520 2676 50  0000 L CNN
F 1 "20k" H 8520 2585 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 8380 2630 50  0001 C CNN
F 3 "~" H 8450 2630 50  0001 C CNN
	1    8450 2630
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 2400 8450 2480
Wire Wire Line
	7900 2400 8450 2400
Wire Wire Line
	8450 3110 8450 3240
$Comp
L power:GND #PWR0189
U 1 1 5C532935
P 8450 3240
F 0 "#PWR0189" H 8450 2990 50  0001 C CNN
F 1 "GND" H 8455 3067 50  0000 C CNN
F 2 "" H 8450 3240 50  0001 C CNN
F 3 "" H 8450 3240 50  0001 C CNN
	1    8450 3240
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 2810 8450 2790
Wire Wire Line
	8450 2790 9220 2790
Connection ~ 8450 2790
Wire Wire Line
	8450 2790 8450 2780
$Comp
L Amplifier_Operational:CA3140 U803
U 1 1 5C538F2E
P 7050 2400
F 0 "U803" H 7350 2500 50  0000 L CNN
F 1 "TL081BCDG4" H 7350 2600 50  0000 L CNN
F 2 "SMD_Packages:SOIC-8-N" H 6950 2300 50  0001 C CNN
F 3 "https://www.digikey.ca/products/en?keywords=TL081BCDG4" H 7050 2400 50  0001 C CNN
	1    7050 2400
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:CA3140 U801
U 1 1 5BDA6B86
P 3650 2500
F 0 "U801" H 3950 2600 50  0000 L CNN
F 1 "CA3140AM" H 3950 2700 50  0000 L CNN
F 2 "SMD_Packages:SOIC-8-N" H 3550 2400 50  0001 C CNN
F 3 "https://www.digikey.ca/product-detail/en/renesas-electronics-america-inc/CA3140AMZ/CA3140AMZ-ND/821387" H 3650 2500 50  0001 C CNN
	1    3650 2500
	1    0    0    -1  
$EndComp
$Comp
L Regulator_SwitchedCapacitor:LM2776 U802
U 1 1 5C53A1E2
P 6790 4840
F 0 "U802" H 6600 5160 50  0000 L CNN
F 1 "LM2776" H 6880 4480 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23-6" H 6840 4490 50  0001 L CNN
F 3 "https://www.digikey.ca/product-detail/en/texas-instruments/LM2776DBVR/296-43957-1-ND/5973203" H 4940 6090 50  0001 C CNN
	1    6790 4840
	1    0    0    -1  
$EndComp
Wire Wire Line
	6790 4540 6790 4450
Wire Wire Line
	7350 2400 7900 2400
Wire Wire Line
	7190 4740 7420 4740
Wire Wire Line
	7690 4740 7690 4660
Wire Wire Line
	6790 5240 6790 5330
$Comp
L power:GND #PWR0190
U 1 1 5C53E693
P 6790 5330
F 0 "#PWR0190" H 6790 5080 50  0001 C CNN
F 1 "GND" H 6870 5180 50  0000 R CNN
F 2 "" H 6790 5330 50  0001 C CNN
F 3 "" H 6790 5330 50  0001 C CNN
	1    6790 5330
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0191
U 1 1 5C53E766
P 6790 4100
F 0 "#PWR0191" H 6790 3950 50  0001 C CNN
F 1 "+5V" H 6790 4250 50  0000 L CNN
F 2 "" H 6790 4100 50  0001 C CNN
F 3 "" H 6790 4100 50  0001 C CNN
	1    6790 4100
	1    0    0    -1  
$EndComp
Connection ~ 6790 4190
Wire Wire Line
	6790 4190 6790 4100
$Comp
L power:GND #PWR0192
U 1 1 5C5401B6
P 7180 4490
F 0 "#PWR0192" H 7180 4240 50  0001 C CNN
F 1 "GND" H 7390 4360 50  0000 R CNN
F 2 "" H 7180 4490 50  0001 C CNN
F 3 "" H 7180 4490 50  0001 C CNN
	1    7180 4490
	1    0    0    -1  
$EndComp
$Comp
L Device:C C811
U 1 1 5C5403CE
P 7180 4340
F 0 "C811" H 7295 4386 50  0000 L CNN
F 1 "2.2uF" H 7295 4295 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 7218 4190 50  0001 C CNN
F 3 "~" H 7180 4340 50  0001 C CNN
	1    7180 4340
	1    0    0    -1  
$EndComp
Wire Wire Line
	6790 4190 7180 4190
$Comp
L Device:C C812
U 1 1 5C5467D8
P 7420 4940
F 0 "C812" H 7535 4986 50  0000 L CNN
F 1 "2.2uF" H 7535 4895 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 7458 4790 50  0001 C CNN
F 3 "~" H 7420 4940 50  0001 C CNN
	1    7420 4940
	1    0    0    -1  
$EndComp
Wire Wire Line
	7420 4790 7420 4740
Connection ~ 7420 4740
Wire Wire Line
	7420 4740 7690 4740
Wire Wire Line
	7420 5090 7420 5150
$Comp
L power:GND #PWR0193
U 1 1 5C54992C
P 7420 5150
F 0 "#PWR0193" H 7420 4900 50  0001 C CNN
F 1 "GND" H 7500 5000 50  0000 R CNN
F 2 "" H 7420 5150 50  0001 C CNN
F 3 "" H 7420 5150 50  0001 C CNN
	1    7420 5150
	1    0    0    -1  
$EndComp
$Comp
L power:-5V #PWR0194
U 1 1 5C54996D
P 7690 4660
F 0 "#PWR0194" H 7690 4760 50  0001 C CNN
F 1 "-5V" H 7705 4788 50  0000 L CNN
F 2 "" H 7690 4660 50  0001 C CNN
F 3 "" H 7690 4660 50  0001 C CNN
	1    7690 4660
	1    0    0    -1  
$EndComp
$Comp
L Device:C C808
U 1 1 5C549C49
P 5930 4990
F 0 "C808" H 6045 5036 50  0000 L CNN
F 1 "2.2uF" H 6045 4945 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 5968 4840 50  0001 C CNN
F 3 "~" H 5930 4990 50  0001 C CNN
	1    5930 4990
	1    0    0    -1  
$EndComp
Wire Wire Line
	6390 4840 6160 4840
Wire Wire Line
	6160 4840 6160 4790
Wire Wire Line
	6160 4790 5930 4790
Wire Wire Line
	5930 4790 5930 4840
Wire Wire Line
	5930 5140 5930 5180
Wire Wire Line
	6310 5040 6390 5040
Wire Wire Line
	5930 5180 6310 5180
Wire Wire Line
	6310 5040 6310 5180
Wire Wire Line
	6390 4740 6290 4740
Wire Wire Line
	6290 4740 6290 4450
Wire Wire Line
	6290 4450 6790 4450
Connection ~ 6790 4450
Wire Wire Line
	6790 4450 6790 4190
NoConn ~ 3650 2200
NoConn ~ 3750 2200
NoConn ~ 3650 2800
NoConn ~ 7050 2100
NoConn ~ 7150 2100
NoConn ~ 7050 2700
$EndSCHEMATC
