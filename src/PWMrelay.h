/*
    PWMrelay - библиотека для генерации низкочастотного ШИМ сигнала для реле (для ПИД регуляторов и проч.)
    Документация: https://alexgyver.ru/pwmrelay/
    GitHub: https://github.com/GyverLibs/PWMrelay
    Возможности:
    - Настройка периода ШИМ
    - Настройка сигнала 0-255 (8 бит)
    - Поддержка реле низкого и высокого уровня
    - Неблокирующий вызов, не использует таймеры (кроме системного), работает на millis()

    AlexGyver, alex@alexgyver.ru
    https://alexgyver.ru/
    MIT License

    Версии:
    v1.1 - убрана реализация из .h
    v1.2 - исправлены мелкие ошибки с совместимостью
*/

#ifndef PWMrelay_h
#define PWMrelay_h
#include <Arduino.h>

class PWMrelay {
public:
    PWMrelay(int pin, bool dir = false, unsigned long period = 1000);	// пин, уровень реле HIGH/LOW, период
    void tick();					// тик, вызывать как можно чаще, сам управляет реле
    void setPWM(byte duty);			// установить величину ШИМ, 0-255. При значении 0 и 255 тик неактивен!
    byte getPWM();					// возвращает величину ШИМ
    void setPeriod(unsigned long period);		// установить период ШИМ в миллисек. (по умолч. 1000мс == 1с)
    unsigned long getPeriod();				// получить период
    void setLevel(bool level);		// установить установить уровень реле (HIGH/LOW)

private:
    bool _flag = false;
    bool _dir = false;
    byte _pin = 0;
    byte _duty = 0;
    unsigned long _period = 1000;
    unsigned long _activePeriod = 0;
    uint32_t _tmr = 0;
};
#endif
