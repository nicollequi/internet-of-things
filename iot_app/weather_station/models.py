from django.db import models

# Create your models here.

class Sensor(models.Model):
    name = models.Charfield (max_length=50)
