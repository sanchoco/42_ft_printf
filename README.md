# ft_printf
기존의 printf 함수와 똑같이 동작하도록 구현

## 주요 내용

라이브러리 이름: libftprintf.a

있어야 할 파일: ✽*.c,* ✽/✽.c, ✽.h, ✽/✽.h

Makefile의 규칙: all, clean, fclean, re, bonus

허용된 함수: malloc, free, write, va_start, va_arg, va_copy, va_end

내용: ft_printf 함수를 포함하는 라이브러리를 작성하십시오.

## 과제의 세부 조건

You have to recode the libc’s printf function

☞ 라이브러리의 실제 함수를 다시 구성해야 함

It must not do the buffer management like the real printf

☞ 버퍼 관리는 하지 말아야 함

It will manage the following conversions: cspdiuxX%

☞ 다음 문자를 처리해야함 : cspdiuxX%

It will manage any combination of the following flags: ’-0.*’ and minimum field

☞ '-0.*' 플래그의 조합을 관리해야 함

man 3 printf / man 3 stdarg

## 해석

%가 나오면 서식문자가 cspdiuxX%로 나와야 끝남.(%%는 '%'로 출력)

**서식 문자의 종류**: (%)%출력, (c)문자, (s)문자열, (p)주소, (d),(i)정수, (u)음수없는 정수(unsigned), (x)16진수 소문자, (X)16진수 대문자

**구성** : %[플래그(flag)][폭(width)][.정밀도(pre)][크기(length)]서식 문자(specifier)

**플래그:** (-) (0) (.) (*)

- 서식 문자에 따라 활용하는 플래그와 옵션이 달라짐.
- (*)은 인자에서 정수형 숫자가 대신 할 수 있음.

    ex) printf("*.*s", 6, 3, "abcdefg"); ⇒ "   abc"

- (-)는 왼쪽 정렬
- (0)는 지정한 자리수만큼 0으로 채움
- (.)는 정밀도로 크기의 앞에 올 수 있음
- (+)는 0이상인 수에 +표시(보너스 파트)

**RETURN값**: printf 함수를 출력한 문자열의 길이(\n, \t, \b 와 같은 문자 포함)

## 구현 방법 및 알고리즘

- 첫 인자인 문자열(format)을 한글자씩 확인하는데 '%'가 나오기 전까진 write함수를 통해 그대로 출력
- '%'문자가 나오게 된다면 **Parsing**을 하면서 플래그와 폭, 정밀도, 크기의 값를 저장함. (구조체 활용)

    (**이 나오는 경우 정밀도 문자(.)가 나오기 전인지 후인지 조건에 따라 저장)*

- 서식 문자인 'c', 's', 'p', 'd', 'd', 'i', 'u', 'x', 'X'가 나오게 되면 옵션 파싱 과정을 멈추고 출력을 위한 알고리즘으로 넘어감.
- 서식 문자의 종류에 따라 변수형에 따른 가변 인자를 불러온 후 이 값을 문자열로 변환.
- 이 문자열을 서식문자마다 이미 파싱된 값을 다르게 활용하여 문자열을 가공하고 출력함.
- 이 과정을 반복하며 출력한 크기를 누적하고  문자열의 끝인 '\0'이 나오면 return값을 반환함.

## 테스트 프로그램

- [https://github.com/Mazoise/42TESTERS-PRINTF](https://github.com/Mazoise/42TESTERS-PRINTF)
- [https://github.com/cclaude42/PFT_2019](https://github.com/cclaude42/PFT_2019)
