#pragma once

#include "primitive.cc"

//---code---
static Integer integer_as_digit(Integer x)
{
    return Integer(x.value - '0');
}
static Integer integer_to_lower_order(Integer x)
{
    return Integer(x.value - 'a');
}
static Integer integer_to_upper_order(Integer x)
{
    return Integer(x.value - 'A');
}
