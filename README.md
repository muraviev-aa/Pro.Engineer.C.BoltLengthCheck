<a name="readme-top"></a>

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![GitHub](https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white)
![CLion](https://img.shields.io/badge/CLion-black?style=for-the-badge&logo=clion&logoColor=white)

## Многомодульная программа
### Консольное приложение "Проверка длины болта по ГОСТ 7798-70"

<p align="center">
<img src="images/bolt.png" alt="drawing" width="150"/>
</p>

#### Цель разработки:

Устранение появления возможных ошибок при работе с болтовыми соединениями в программе Tekla Structures и ручном подборе длины болта. 

#### Описание возможной ошибки: 
При копировании болтов "в другой объект", в случае изменения толщин соединяемых деталей, Tekla Structures программно не меняет длину болта в сторону уменьшения или увеличения. Формально болт продолжает соединять детали, но имеет некорректную длину. Игнорирование проверки длины болта приведёт к тому, что на монтаже будет невозможно закрутить гайку (длинный болт), либо резьба будет заходить в крайнюю к гайке деталь более 0,5t (короткий болт).

#### Приложение позволяет проверить длину болта по следующим параметрам:

* расположении резьбы болта на глубине не более 0,5t в ближней к гайке детали;
* возможность закручивания гайки (резьба болта не выходит из шайбы);
* размер выхода резьбы болтов из гаек.

#### Приложение имеет справку:

<p align="center">
<img src="images/help.png" alt="drawing" width="650"/>
</p>

#### Приложение обрабатывает следующие аргументы командной строки:

* -h Описание функционала приложения;
* -f <filename.csv> Указание входного файла *.csv для обработки.
* -m Указание диаметра болта;
* -l Указание длины болта;
* -s Указание суммарной толщины соединяемых деталей за исключением толщины ближней к гайке детали;
* -t Указание толщины ближней к гайке детали;
* -w Указание количества шайб под головкой болта;
* -t Указание количества шайб под гайками;

#### Сборка приложения осуществляется при помощи утилиты make.

#### Файл для тестирования работы приложения:

* 7798.csv

#### Примеры работы приложения:

* длина болта удовлетворяет всем перечисленным требованиям

<p align="center">
<img src="images/yes_yes_yes.png" alt="drawing" width="650"/>
</p>

* резьба болта выходит из шайбы, гайка не закрутится

<p align="center">
<img src="images/yes_no_yes.png" alt="drawing" width="650"/>
</p>

* резьба болта входит в ближнюю к гайке деталь более чем на 0,5t, резьбовой конец короткий

<p align="center">
<img src="images/no_yes_no.png" alt="drawing" width="650"/>
</p>

#### Реализована проверка параметров, введенных пользователем:

* контроль диаметра болта

<p align="center">
<img src="images/error_diam.png" alt="drawing" width="650"/>
</p>

* контроль длины болта по ГОСТ 7798-70

<p align="center">
<img src="images/error_length.png" alt="drawing" width="650"/>
</p>

* контроль нерекомендованных к применению длин болтов

<p align="center">
<img src="images/length_not_recom.png" alt="drawing" width="650"/>
</p>

#### Примеры написания командной строки для запуска:

bolt

bolt -h

bolt -f 7798.csv -m 16 -l 65 -s 10 -t 10 -w 1 -n 2

bolt -f 7798.csv -m 20 -l 80 -s 20 -t 10 -w 1 -n 1

#### Состав репозитория:
<url> &#128194; bolt_check </url> - файлы проекта

<url> &#128194; images </url> - файлы *.png для README.md

<p align="right">(<a href="#readme-top">вверх</a>)</p>
