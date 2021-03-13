#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <IRrecv.h>
#include <key_button_util.h>
#include <key_button_util.h>



int RECV_PIN = D1;
IRrecv irrecv = IRrecv(RECV_PIN);
decode_results results;

void setUpRemote(uint8_t recv_pin)
{
    //irrecv  =  IRrecv(RECV_PIN);
    pinMode(RECV_PIN, INPUT);
    irrecv.enableIRIn();
}

///Tra ve hed cua button
uint64_t getHexButtonDown()
{
    if (irrecv.decode(&results))
    {
        return results.value;
    }
    return 0;
}

///HIen thi man hinh hex cua button
void printHexButtonDown()
{
    if (irrecv.decode(&results))
    {
        Serial.printf("val = 0x%x\n", results.value);
        irrecv.resume();
    }
}

///Lay thong tin cua Nha san xuat remote
void getInfoRemote()
{
    if (irrecv.decode(&results))
    {

        switch (results.decode_type)
        {
        case NEC:
            Serial.println("NEC");
            break;
        case SONY:
            Serial.println("SONY");
            break;
        case RC5:
            Serial.println("RC5");
            break;
        case RC6:
            Serial.println("RC6");
            break;
        case DISH:
            Serial.println("DISH");
            break;
        case SHARP:
            Serial.println("SHARP");
            break;
        case JVC:
            Serial.println("JVC");
            break;
        case SANYO:
            Serial.println("SANYO");
            break;
        case MITSUBISHI:
            Serial.println("MITSUBISHI");
            break;
        case SAMSUNG:
            Serial.println("SAMSUNG");
            break;
        case LG:
            Serial.println("LG");
            break;
        case WHYNTER:
            Serial.println("WHYNTER");
            break;
        case AIWA_RC_T501:
            Serial.println("AIWA_RC_T501");
            break;
        case PANASONIC:
            Serial.println("PANASONIC");
            break;
        case DENON:
            Serial.println("DENON");
            break;
        default:
        case UNKNOWN:
            Serial.println("UNKNOWN");
            break;
        }
        irrecv.resume();
    }
}
