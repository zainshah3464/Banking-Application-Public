import time
import pyautogui
import pywhatkit as kit
import sys

def format_number(number):
    """Convert Pakistani phone number format to international format (+92)"""
    if number.startswith("0"):
        return "+92" + number[1:]  # Convert 0345XXXXXXX → +92345XXXXXXX
    return number  # If already in +92 format, return as is

def send_whatsapp(phone):
    phone = format_number(phone)  # Convert number format
    
    # Read the message from the file
    with open("message.txt", "r") as file:
        message = file.read().strip()  # Remove extra spaces or new lines

    print(f"Sending message to {phone}...\nMessage:\n{message}")
    kit.sendwhatmsg_instantly(phone, message, wait_time=29, tab_close=True)

    time.sleep(25)  # Wait for message to send

    # Close WhatsApp Web tab using Ctrl+W
    pyautogui.hotkey('f11')
    time.sleep(3)


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python whatsapp_sender.py <phone_number>")
        sys.exit(1)
    
    phone = sys.argv[1]
    send_whatsapp(phone)
