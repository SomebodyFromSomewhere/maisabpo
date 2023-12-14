# Большие числа
## Реализации
- Строки
- Основания
- Столбик


## Оптимизации
- Если число можно хранить в стандартном типе, то не следует его пытаться представлять иначе.

Реализация конструктора для long от разработчиков .NET 
```c#
public BigInteger(long value)
 {
   if ((long) int.MinValue <= value && value <= (long) int.MaxValue)
   {
     if (value == (long) int.MinValue)
     {
       this = BigInteger.s_bnMinInt;
     }
     else
     {
       this._sign = (int) value;
       this._bits = (uint[]) null;
     }
   }
   else
   {
     ulong num;
       if (value < 0L)
       {
         num = (ulong) -value;
         this._sign = -1;
        }
       else
        {
         num = (ulong) value;
         this._sign = 1;
        }
       this._bits = new uint[2];
       this._bits[0] = (uint) num;
       this._bits[1] = (uint) (num >> 32);
   }
 }
```


[видео](https://youtu.be/lequtnBj8co?si=Dgd7OuyHp2rMLME4):


