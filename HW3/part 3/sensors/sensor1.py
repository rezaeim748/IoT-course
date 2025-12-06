import time
import random
import paho.mqtt.client as mqtt

broker_address = "127.0.0.1"
port = 1883

client = mqtt.Client("Sensor1")

client.connect(broker_address, port)

while True:
    temperature = random.uniform(20, 30)
    humidity = random.uniform(40, 60)

    client.publish("topic/sensor1/temperature", f"{temperature:.2f}")
    client.publish("topic/sensor1/humidity", f"{humidity:.2f}")

    time.sleep(5)
