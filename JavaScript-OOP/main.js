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

// mama.calcAge();
// nuke.calcAge();

Person.prototype.newTrait = "deaf";
// console.dir(Person.prototype.constructor);

const arr = [1, 23, 4, 5, 1, 5];

Array.prototype.unique = function () {
  return [...new Set(this)];
};

console.log(arr.unique());
