"use strict";

const Person = function (firstName, birthYear) {
  this.firstName = firstName;
  this.birthYear = birthYear;
};

const mama = new Person("chloro", 2000);
const nuke = new Person("nuk", 2010);

Person.prototype.calcAge = function () {
  console.log(2024 - this.birthYear);
};

mama.calcAge();
nuke.calcAge();
