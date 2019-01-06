Usage
=====

Generic input an output
-----------------------

Most of the libraries described here inherit from either a generic input or
output class.

Input
^^^^^

The constructor for input devices (e.g., a button or photoresistor) takes up to
three parameters of which two are optional.

.. list-table:: Generic input constructor parameters.
   :header-rows: 1

   * - parameter
     - description
     - mandatory
     - default
   * - 0
     - Pin number.
     - yes
     -
   * - 1
     - Invert input behaviour.
     - no
     - ``false``
   * - 2
     - Use internal pullup resistor.
     - no
     - ``false``

Every input device has at least the following functions.

.. list-table:: Generic input functions.
   :header-rows: 1

   * - name
     - description
   * - ``analogRead``
     - Read an analogue value.
   * - ``digitalRead``
     - Read a digital value.
   * - ``on``
     - Check whether the state is HIGH.
   * - ``off``
     - Check whether the state is LOW.

Output
^^^^^^

The constructor for output devices (e.g., a buzzer or an LED) takes up to two
parameters of which one is optional.

.. list-table:: Generic output constructor parameters.
   :header-rows: 1

   * - parameter
     - description
     - mandatory
     - default
   * - 0
     - Pin number.
     - yes
     -
   * - 1
     - Invert output behaviour.
     - no
     - ``false``

Every output device has at least the following functions.

.. list-table:: Generic output functions.
   :header-rows: 1

   * - name
     - description
   * - ``analogWrite``
     - Write an analogue value.
   * - ``digitalWrite``
     - Write a digital value.
   * - ``on``
     - Write HIGH.
   * - ``off``
     - Write LOW.


Button
------

Include the header file to use the button library.

.. code:: cpp

    #include <button.h>

Example
^^^^^^^

We make a ``Button`` instance that uses pin ``10`` follows.

.. code:: cpp

    Button button(10);

Check whether the button is pressed by using the ``on()`` function.

.. code:: cpp

    if (button.on()) {
      // Button is pressed.
    }


Buzzer
------

Include the header file to use the buzzer library.

.. code:: cpp

    #include <buzzer.h>

Example
^^^^^^^

We make a ``Buzzer`` instance that uses pin ``10`` as follows.

.. code:: cpp

    Buzzer buzzer(10);

To generate a tone of 10,000Hz, use the ``tone()`` member function.

.. code:: cpp

    buzzer.tone(10000);

The buzzer can be turned off with the ``noTone()`` member function.

.. code:: cpp

    buzzer.noTone();


LED
---

Include the header file to use the LED library.

.. code:: cpp

    #include <led.h>

Example
^^^^^^^

We make a ``LED`` instance that uses pin ``10`` as follows.

.. code:: cpp

    LED led(10);

The led can be turned on or off.

.. code:: cpp

    led.on();
    led.off();

If the pin supports analogue output, the LED can also be set to a specific
brightness.

.. code:: cpp

    led.analogWrite(20);


PhotoResistor
-------------

Include the header file to use the photoresistor library.

.. code:: cpp

    #include <photoresistor.h>

Example
^^^^^^^

We make a ``PhotoResistor`` instance that uses pin ``10`` as follows.

.. code:: cpp

    PhotoResistor photoresistor(10);

The value of the photoresistor can be read with the ``analogRead()`` function.

.. code:: cpp

    photoresistor.analogRead();


Thermistor
----------

Include the header file to use the thermistor library.

.. code:: cpp

    #include <thermistor.h>

Example
^^^^^^^

The constructor for the thermistor is slightly different from the generic one.
It takes an additional mandatory parameter named ``resistor`` with which the
resistor value (in Ω) should be passed.

We make a ``Thermistor`` instance that uses pin ``10`` and uses an 100Ω
resistor as follows.

.. code:: cpp

    Thermistor thermistor(10, 100.0);

The temperature can be read using various functions.

.. code:: cpp

    thermistor.kelvin();
    thermistor.celsius();
    thermistor.fahrenheit();


Microphone
----------

Include the header file to use the microphone library.

.. code:: cpp

    #include <microphone.h>

Example
^^^^^^^

We make a ``Microphone`` instance that uses pin ``A4`` as follows.

.. code:: cpp

    Microphone microphone(A4);

The sound level of the microphone can be read with the ``soundLevel()``
function which takes a number of samples and determines the range of these
samples. If we want to determine the sound level based on 1024 samples, we do
the following.

.. code:: cpp

    microphone.soundLevel(1024);
